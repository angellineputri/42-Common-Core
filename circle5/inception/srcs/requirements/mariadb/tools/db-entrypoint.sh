#!/bin/bash
set -e

MAX_RETRIES=100
COUNT=0

: "${MYSQL_DATABASE:?Need to set MYSQL_DATABASE}"
: "${MYSQL_USER:?Need to set MYSQL_USER}"
: "${DB_ADMIN_NAME:?Need to set DB_ADMIN_NAME}"

DB_USER_PASSWORD_FILE="/run/secrets/db_user_password"
DB_ADMIN_PASSWORD_FILE="/run/secrets/db_admin_password"
DB_ROOT_PASSWORD_FILE="/run/secrets/db_root_password"

DB_NAME=$MYSQL_DATABASE
DB_USER=$MYSQL_USER
DB_USER_PASSWORD=$(cat "$DB_USER_PASSWORD_FILE")
DB_ADMIN_PASSWORD=$(cat "$DB_ADMIN_PASSWORD_FILE")
DB_ROOT_PASSWORD=$(cat "$DB_ROOT_PASSWORD_FILE")

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

if [ ! -d /var/lib/mysql/mysql ]; then
    echo "Initializing MariaDB database..."
    mysqld --initialize-insecure --user=mysql
fi

echo "Starting MariaDB initialization..."
mysqld --user=mysql --skip-networking --skip-grant-tables &
PID=$!

until mysqladmin ping --silent; do
    COUNT=$((COUNT+1))
    if [ "$COUNT" -ge "$MAX_RETRIES" ]; then
        echo "MariaDB did not start in time, exiting."
        exit 1
    fi
done

echo "Setting root password..."
mysql <<-EOF
    FLUSH PRIVILEGES;
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
EOF

echo "Creating database and users..."
mysql -u root -p"${DB_ROOT_PASSWORD}" <<-EOF
    CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
    CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USER_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
    CREATE USER IF NOT EXISTS '${DB_ADMIN_NAME}'@'%' IDENTIFIED BY '${DB_ADMIN_PASSWORD}';
    GRANT ALL PRIVILEGES ON *.* TO '${DB_ADMIN_NAME}'@'%' WITH GRANT OPTION;
    FLUSH PRIVILEGES;
EOF

kill "$PID"
wait "$PID" 2>/dev/null || true

echo "Starting MariaDB..."
exec mysqld --user=mysql --bind-address=0.0.0.0
