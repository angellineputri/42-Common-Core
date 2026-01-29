#include "../../inc/http/HttpRequest.hpp"

const std::string &HttpRequest::method() const
{
    return _m;
}

const std::string &HttpRequest::target() const
{
    return _t;
}

const std::string &HttpRequest::version() const
{
    return _v;
}

const HttpHeaders &HttpRequest::headers() const
{
    return _h;
}

std::string HttpRequest::header(const std::string &k) const
{
    return _h.get(k);
}

void HttpRequest::setMethod(const std::string &m)
{
    _m = m;
}

void HttpRequest::setTarget(const std::string &t)
{
    _t = t;
}

void HttpRequest::setVersion(const std::string &v)
{
    _v = v;
}

void HttpRequest::setHeader(const std::string &k, const std::string &v)
{
    _h.set(k, v);
}

void HttpRequest::setBody(const std::string &b)
{
    _b = b;
}

const std::string &HttpRequest::body() const
{
    return _b;
}
