FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    php-zip \
    wget \
    curl \
    mariadb-client \
    sudo \
    php-redis \
    cron \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php && \
    mkdir -p /var/www/.wp-cli/cache && \
    mkdir -p /var/www/html/wp-content/upgrade && \
    mkdir -p /var/www/html/wp-content/uploads && \
    chown -R www-data:www-data /var/www/.wp-cli/cache && \
    chown -R www-data:www-data /var/www/html/wp-content/ && \
    chmod -R 755 /var/www/html/wp-content

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz --strip-components=1 && \
    rm latest.tar.gz

RUN chown -R www-data:www-data /var/www/html && \
    sed -i 's|^listen = .*|listen = 9000|' /etc/php/8.2/fpm/pool.d/www.conf

COPY tools/wp-entrypoint.sh /usr/local/bin/wp-entrypoint.sh
RUN chmod +x /usr/local/bin/wp-entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wp-entrypoint.sh"]
CMD ["php-fpm8.2", "-F"]
