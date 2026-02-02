## Developer Documentation

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

### Environment Setup
1. **Prerequisites**
- Docker installed
- Docker compose installed
- Make installed
- Access to folder /home/aputri-a/data

2. **Configuration Files and Secrets**
- Place sensitive credentials in the secrets/ folder:
    - database/db_admin_password.txt
    - database/db_root_password.txt
    - database/db_user_password.txt
    - ftp/ftp_password.txt
    - wordpress/wp_admin_email.txt
    - wordpress/wp_admin_password.txt
    - wordpress/wp_user_email.txt
    - wordpress/wp_user_password.txt

- Environment variables are stored in srcs/.env:
    - DOMAIN_NAME
    - MYSQL_DATABASE (mysql database name)
    - MYSQL_USER (mysql username)
    - DB_ADMIN_NAME
    - DB_HOSTNAME
    - WP_ADMIN_NAME
    - WP_USER
    - FTP_USER

### Building and Launching the project
- Build and start all containers:
    cmd: `make`
- Stop and clean the project:
    cmd: `make fclean`

### Managing Containers and Volumes
- List running containers:
    cmd: `docker ps -a`
- Check container logs:
    cmd: `docker logs <container_name>`
- List docker volumes:
    cmd: `docker volume ls`
- Inspect a volume
    cmd: `docker volume inspect <volume_name>`

### Project Data and Persistence
Wordpress files and MariaDB data are stored in named volumes:
- db_data: MariaDB database
- wp_data: Wordpress files
- portainer_data: Portainer login, state, and configuration

Named volumes persist data independently of containers, meaning that deleting a container does not delete the data, and data is isolated from the host filesystem but managed by Docker.
On the host, the volume data is stored inside /home/aputri-a/data

### Accessing Services
- **Website:** `https://aputri-a.42.fr`
- **Wordpress Admin:** `https://aputri-a.42.fr/wp-admin`
- **Static Site:** `https://aputri-a.42.fr/static_site`
- **Adminer:** `https://aputri-a.42.fr/adminer`
- **Portainer:** `https://aputri-a.42.fr/portainer`
- **FTP:** host: `aputri-a.42.fr`, port: `21`, credentials from secrets

### Other Usefull Commands
- Enter a container shell:
    cmd: `docker exec -it <container_name> bash`
- Restart a container
    cmd: `docker restart <container_name>`
- Check images
    cmd: `docker images`
- Remove image
    cmd: `docker rmi <image_name>`
- Remove a container
    cmd: `docker rm -f <container_name>`