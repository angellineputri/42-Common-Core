FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    vsftpd \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/vsftpd/empty

COPY conf/vsftpd.conf /etc/vsftpd.conf

COPY tools/ftp-entrypoint.sh /ftp-entrypoint.sh
RUN chmod +x /ftp-entrypoint.sh

EXPOSE 21
EXPOSE 21000-21010

ENTRYPOINT ["/ftp-entrypoint.sh"]

CMD [ "vsftpd", "/etc/vsftpd.conf" ]