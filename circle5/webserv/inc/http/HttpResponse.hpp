#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>
#include "http/HttpHeaders.hpp"

class HttpResponse {
    private:
        int         _status;
        std::string _reason;
        HttpHeaders _headers;
        std::string _body;

    public:
        HttpResponse();
        HttpResponse(int code, const std::string &reason);

        void setStatus(int code, const std::string &reason);
        int status() const;
        const std::string &reason() const;

        void addHeader(const std::string &k, const std::string &v);
        std::string header(const std::string &k) const;
        bool hasHeader(const std::string &k) const;
        const HttpHeaders &headers() const;

        void setBody(const std::string &b);
        const std::string &body() const;
};

#endif
