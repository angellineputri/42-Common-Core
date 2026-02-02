#!/bin/bash
set -e

: "${FTP_USER:?Need to set FTP_USER}"

FTP_PASSWORD_FILE="/run/secrets/ftp_password"
FTP_PASSWORD=$(cat "$FTP_PASSWORD_FILE")

if ! id "$FTP_USER" >/dev/null 2>&1; then
    useradd -m -d /var/www/html/ "$FTP_USER"
fi

echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

usermod -aG www-data $FTP_USER

chown -R $FTP_USER:www-data /var/www/html/
chmod -R 775 /var/www/html/
chmod g+s /var/www/html/

exec "$@"
