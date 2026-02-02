_This project has been created as part of the 42 curriculum by aputri-a_

### Description
The inception project sets up a small web infrastructure using Docker containers. Its goal is to provide a secure and persistent web stack using Docker while focusing on Docker best practices (containerization, persistent storage, and secure service communication).
The project includes:
- NGINX container (handles HTTPS traffic using TLSv1.2 or TLSv1.3)
- Wordpress container without NGINX (serves the website)
- Mariadb container without NGINX (database service)
- [bonus] Redis container (provides caching for wordpress)
- [bonus] FTP container (allows file transfer to wordpress directory)
- [bonus] Static Site container (additional static content)
- [bonus] Adminer container (database visualization for mariaDB)
- [bonus] Portainer container (web interface to manage docker containers)
- Persistent named volumes (wordpress files and database stored in */home/aputri-a/data*)
- Custom Docker Network (connects containers securely)

### Design Choices
1. **Virtual Machines vs Docker**: Docker is lightweight, faster to deploy, and isolates services efficiently, while virtual machines are heavier and require more system resources.

2. **Secrets vs Environment Variables**: Secrets are used for sensitive data (passwords), environment variables for configuration values (usernames, domain name).

3. **Docker Network vs Host Network**: The custom Docker network isolates containers and improves security; host network exposes services directly to the host.

4. **Docker Volumes vs Bind Mounts**: Named volumes are preferred because they are managed by Docker, persist data independently of the container lifecycle, and work reliably across different systems. Bind mounts depend on host paths, which can lead to permission issues, path errors, or accidental data loss.

### Instructions
1. Clone the repository
2. Place the credentials inside the secrets/ folder 
- database/db_admin_password.txt
- database/db_root_password.txt
- database/db_user_password.txt
- ftp/ftp_password.txt
- wordpress/wp_admin_email.txt
- wordpress/wp_admin_password.txt
- wordpress/wp_user_email.txt
- wordpress/wp_user_password.txt
3. Build and run the docker images using Makefile (`make` command)
4. Access the website at https://aputri-a.42.fr
5. Access the user login page at https://aputri-a.42.fr/wp-admin
6. Access the static site at https://aputri-a.42.fr/static_site
7. Access the adminer page at https://aputri-a.42.fr/adminer
8. Access the portainer page at https://aputri-a.42.fr/portainer
9. Use ftp using the command 'ftp aputri-a.42.fr' on the terminal
5. Stop and clean the project by running `make fclean`

### Resources
- https://youtu.be/LjL_N0OZxvY?si=zet4Z0IjuMnxd9gs
- https://en.wikipedia.org/wiki/Docker_(software)
- https://www.ibm.com/think/topics/docker
- https://www.geeksforgeeks.org/devops/docker-compose/
- https://docs.docker.com/reference/dockerfile/
- https://www.geeksforgeeks.org/devops/what-is-docker-image/
- https://docs.docker.com/compose/how-tos/networking/
- https://www.geeksforgeeks.org/devops/docker-volume-vs-bind-mount/
- https://stackoverflow.com/questions/36387032/how-to-set-a-path-on-host-for-a-named-volume-in-docker-compose-yml
- https://docs.docker.com/engine/storage/volumes/
- https://docs.docker.com/engine/storage/bind-mounts/
- https://stackoverflow.com/questions/21553353/what-is-the-difference-between-cmd-and-entrypoint-in-a-dockerfile
- https://en.wikipedia.org/wiki/MariaDB
- https://stackoverflow.com/questions/59547067/what-is-the-configuration-file-of-mariadb
- https://wordpress.org/documentation/
- https://nginx.org/en/docs/
- https://nginx.org/en/docs/http/configuring_https_servers.html
- https://stackoverflow.com/questions/10175812/how-can-i-generate-a-self-signed-ssl-certificate-using-openssl
- https://serversforhackers.com/c/redirect-http-to-https-nginx
- https://www.geeksforgeeks.org/system-design/what-is-the-default-port-for-redis/
- https://stackoverflow.com/questions/65070121/how-to-configure-vsftpd-with-docker
- https://forums.docker.com/t/how-to-run-vsftpd-service-when-a-container-starts/99755
- https://www.adminer.org/en/
- https://stackoverflow.com/questions/52480057/install-adminer-on-ubuntu-18-04-bionic
- https://docs.portainer.io/start/install-ce/server/docker/linux

In addition to the referenced articles, I also used AI in this project to help me better understand the project requirements, the service descriptions, and how to use the services effectively. AI also helped me clarify any hesitations, questions, or doubts I had regarding commands, tasks, or concepts.
