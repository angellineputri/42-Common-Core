# webserv

An HTTP/1.1 web server written in C++98. Uses non-blocking I/O with `select`/`poll` to handle multiple simultaneous connections without threads.

## Features

- HTTP methods: `GET`, `POST`, `DELETE`
- Chunked transfer encoding
- CGI execution (scripts via environment variables and stdin/stdout)
- File uploads
- Virtual hosts (multiple server blocks in one config)
- Configurable routing: root, index, redirects, allowed methods, autoindex
- Custom error pages
- Configurable client body size limit

## Build

```sh
make
make clean
make fclean
make re
```

## Run

```sh
./webserv [config_file]
```

## Config file

Loosely inspired by NGINX config syntax:

```nginx
server {
    listen      8080;
    server_name localhost;
    root        ./www;
    index       index.html;

    location / {
        methods GET POST;
    }

    location /upload {
        methods POST DELETE;
        upload_path ./uploads;
    }

    location /cgi-bin {
        cgi_pass .py;
    }
}
```

## Project structure

| Path | Contents |
|------|----------|
| `inc/` | header files |
| `inc/config/` | config parser headers |
| `inc/http/` | HTTP request/response headers |
| `src/` | source files |
| `src/config/` | config file tokenizer and parser |
| `src/http/` | HTTP request parser, response writer |
| `src/Server/` | connection handling, CGI, GET/POST handlers |
