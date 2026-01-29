#ifndef REQUEST_PARSER_HPP
#define REQUEST_PARSER_HPP

#include <string>
#include <cstddef>
#include "http/HttpRequest.hpp"

class HttpRequestParser {
    public:
        enum Result {
            INCOMPLETE,
            COMPLETE,
            ERROR
        };

        HttpRequestParser();

        Result feed(const char *data, size_t len, HttpRequest &outReq, std::string &outErr, size_t max_body_size);
        void reset();

    private:
        enum State {
            REQUEST_LINE,
            HEADERS,
            BODY_CL,
            DONE,
            ERR
        };

        State _state;
        std::string _buffer;
        size_t _needBodyBytes;
        size_t _headerCount;
        size_t _headerBytes;
        size_t _bodyBytes;
        bool _sawContentLength;
        size_t _contentLength;

        bool consumeCRLFLine(std::string &outline);
        static std::string trim(const std::string &s);
        static std::string toLower(const std::string &s);
        bool parseRequestLine(const std::string &line, HttpRequest &req, std::string &err);
        bool parseHeaderLine(const std::string &line, HttpRequest &req, std::string &err);
        bool finishHeaders(HttpRequest &req, std::string &err);
};

#endif
