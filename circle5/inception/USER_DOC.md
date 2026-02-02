## User Documentation

### Overview
The Inception project provides a secure web infrastructure with the following services:
- **NGINX:** HTTPS traffic handling
- **WordPress:** Website content
- **MariaDB:** Database for WordPress
- **[Bonus] Redis:** Caching for wordpress
- **[Bonus] FTP:** FIle transfer to wordpress
- **[Bonus] Static Site:** Serves additional static content
- **[Bonus] Adminer:** Web-based database management for mariaDB
- **[Bonus] Portainer:** Web-based docker management interface

### Starting and Stopping the Project
- **Start**: `make`
- **Stop**: `make fclean`

### Accessing Services
- **Website:** `https://aputri-a.42.fr`
- **Wordpress Admin:** `https://aputri-a.42.fr/wp-admin`
- **Static Site:** `https://aputri-a.42.fr/static_site`
- **Adminer:** `https://aputri-a.42.fr/adminer`
- **Portainer:** `https://aputri-a.42.fr/portainer`
- **FTP:** host: `aputri-a.42.fr`, port: `21`, credentials from secrets

### Managing Credentials
Sensitive credentials are stored in the secrets/ folder in their corresponding files:
- database/db_admin_password.txt
- database/db_root_password.txt
- database/db_user_password.txt
- ftp/ftp_password.txt
- wordpress/wp_admin_email.txt
- wordpress/wp_admin_password.txt
- wordpress/wp_user_email.txt
- wordpress/wp_user_password.txt

Environment variables for configuration values are stored in srcs/.env file.
- DOMAIN_NAME
- MYSQL_DATABASE (mysql database name)
- MYSQL_USER (mysql username)
- DB_ADMIN_NAME
- DB_HOSTNAME
- WP_ADMIN_NAME
- WP_USER
- FTP_USER

### Checking Services
To check that the services are running correctly
- `docker ps -a` (lists running containers)
- `docker logs <container name>` (check logs for errors)
- `docker volume ls` (check named volumes)