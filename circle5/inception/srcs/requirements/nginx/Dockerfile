FROM debian:bookworm

RUN apt update && apt install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /run/nginx /etc/ssl/private /var/www/html

RUN openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -subj "/CN=aputri-a.42.fr" \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/private/nginx.crt \
    && chown -R www-data:www-data /etc/ssl/private

COPY conf/default.conf /etc/nginx/conf.d/default.conf

EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
