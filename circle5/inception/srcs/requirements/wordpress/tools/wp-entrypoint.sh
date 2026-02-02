#!/bin/bash
set -e

MAX_RETRIES=100
COUNT=0

: "${MYSQL_DATABASE:?Need to set MYSQL_DATABASE}"
: "${MYSQL_USER:?Need to set MYSQL_USER}"
: "${DB_HOSTNAME:?Need to set DB_HOSTNAME}"
: "${WP_USER:?Need to set WP_USER}"
: "${WP_ADMIN_NAME:?Need to set WP_ADMIN_NAME}"
: "${DB_PORT:?Need to set DB_PORT}"

DB_USER_PASSWORD_FILE=/run/secrets/db_user_password
WP_ADMIN_PASSWORD_FILE=/run/secrets/wp_admin_password
WP_ADMIN_EMAIL_FILE=/run/secrets/wp_admin_email
WP_USER_PASSWORD_FILE=/run/secrets/wp_user_password
WP_USER_EMAIL_FILE=/run/secrets/wp_user_email

DB_NAME=$MYSQL_DATABASE
DB_USER=$MYSQL_USER
DB_USER_PASSWORD=$(cat "$DB_USER_PASSWORD_FILE")

WP_ADMIN_PASSWORD=$(cat "$WP_ADMIN_PASSWORD_FILE")
WP_ADMIN_EMAIL=$(cat "$WP_ADMIN_EMAIL_FILE")
WP_USER_PASSWORD=$(cat "$WP_USER_PASSWORD_FILE")
WP_USER_EMAIL=$(cat "$WP_USER_EMAIL_FILE")

echo "Waiting for MariaDB at $DB_HOSTNAME..."
until mariadb -h "$DB_HOSTNAME" -P "$DB_PORT" -u "$DB_USER" -p"$DB_USER_PASSWORD" -e "SELECT 1;" >/dev/null 2>&1; do
    COUNT=$((COUNT+1))
    if [ "$COUNT" -ge "$MAX_RETRIES" ]; then
        exit 1
    fi
done
echo "MariaDB is ready!"

echo "Generating wp-config.php..."
rm -f wp-config.php 

cat > wp-config.php <<EOF
<?php
define( 'DB_NAME', '$DB_NAME' );
define( 'DB_USER', '$DB_USER' );
define( 'DB_PASSWORD', '$DB_USER_PASSWORD' );
define( 'DB_HOST', '${DB_HOSTNAME}:${DB_PORT}' );
define( 'DB_CHARSET', 'utf8mb4' );
define( 'DB_COLLATE', '' );

define( 'AUTH_KEY',         'put your unique phrase here' );
define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );
define( 'LOGGED_IN_KEY',    'put your unique phrase here' );
define( 'NONCE_KEY',        'put your unique phrase here' );
define( 'AUTH_SALT',        'put your unique phrase here' );
define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );
define( 'LOGGED_IN_SALT',   'put your unique phrase here' );
define( 'NONCE_SALT',       'put your unique phrase here' );

define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );
define( 'WP_REDIS_DATABASE', 0 );

\$table_prefix = 'wp_';
define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
EOF

if ! command -v wp >/dev/null 2>&1; then
    echo "Installing WP-CLI"
    curl -s -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

if ! wp core is-installed --allow-root >/dev/null 2>&1; then
    echo "Installing WordPress..."
    sudo -u www-data wp core install \
        --url="https://aputri-a.42.fr" \
        --title="Inception" \
        --admin_user="$WP_ADMIN_NAME" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root
    sudo -u www-data wp user create \
        $WP_USER \
        $WP_USER_EMAIL \
        --role=subscriber \
        --user_pass="$WP_USER_PASSWORD"
fi

echo "Installing and activating the Astra theme..."
sudo -u www-data wp theme install astra --activate

echo "enabling redis"
sudo -u www-data wp plugin install redis-cache --activate
sudo -u www-data wp redis enable

exec "$@"
