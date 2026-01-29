#include "../inc/ClientState.hpp"

ClientState::ClientState()
    : server(0),
      parser(),
      request(),
      session(0),
      sessionId(),
      username(),
      maxBodySize(0),
      keep_alive(false),
      fd(-1),
      port(0),
      server_name(),
      ip(),
      want_write(false),
      read_buf(),
      write_buf(),
      parse_err(),
      cgi_pid(-1),
      cgi_fd(-1),
      cgi_start_time(0),
      cgi_buffer(),
      cgi_active(false)
{}
