FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    curl \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /opt/portainer \
    && curl -L https://github.com/portainer/portainer/releases/download/2.20.3/portainer-2.20.3-linux-amd64.tar.gz \
       -o /tmp/portainer.tar.gz \
    && tar -xz --strip-components=1 -f /tmp/portainer.tar.gz -C /opt/portainer \
    && rm /tmp/portainer.tar.gz

EXPOSE 9000

CMD ["/opt/portainer/portainer", "--data", "/data", "--base-url", "/portainer", "--bind", "0.0.0.0:9000"]
