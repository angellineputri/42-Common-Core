FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    wget \
    php \
    php-mysqli \
    && mkdir -p /var/www/html \
    && rm -rf /var/lib/apt/lists/*

RUN wget -O /var/www/html/index.php https://www.adminer.org/latest.php \
    && chown -R www-data:www-data /var/www/html

EXPOSE 80

CMD ["php", "-S", "0.0.0.0:80", "-t", "/var/www/html"]