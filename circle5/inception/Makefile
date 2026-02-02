DOCKER_COMPOSE_FILE = srcs/docker-compose.yml
COMPOSE = docker-compose -f $(DOCKER_COMPOSE_FILE)
DATA_DIR = /home/aputri-a/data
all: up

up:
	mkdir -p $(DATA_DIR)/mariadb
	mkdir -p $(DATA_DIR)/wordpress
	$(COMPOSE) up --detach

down:
	$(COMPOSE) down --remove-orphans

build:
	$(COMPOSE) build

logs:
	$(COMPOSE) logs

ps:
	$(COMPOSE) ps -a

restart: down up

clean:
	$(COMPOSE) down --remove-orphans

fclean:
	$(COMPOSE) down -v --rmi all --remove-orphans

# prune:
# 	$(COMPOSE) down --remove-orphans
# 	docker system prune -a --volumes --force

re: fclean all

.PHONY: all up down stop build logs ps restart clean fclean re
