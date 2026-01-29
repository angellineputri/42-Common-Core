#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <cstddef>
#include "http/HttpHeaders.hpp"

class HttpRequest {
    private:
        std::string _m;
        std::string _t;
        std::string _v;
        std::string _b;
        HttpHeaders _h;

    public:
        const std::string &method() const;
        const std::string &target() const;
        const std::string &version() const;
        const HttpHeaders &headers() const;
        std::string header(const std::string &k) const;

        void setMethod(const std::string &m);
        void setTarget(const std::string &t);
        void setVersion(const std::string &v);
        void setHeader(const std::string &k, const std::string &v);
        void setBody(const std::string &b);
        const std::string &body() const;
};

#endif
