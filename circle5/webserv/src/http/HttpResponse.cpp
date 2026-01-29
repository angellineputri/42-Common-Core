#include "../../inc/http/HttpResponse.hpp"

HttpResponse::HttpResponse()
{
    _status = 200;
    _reason = "OK";
    _body = "";
}

HttpResponse::HttpResponse(int code, const std::string &reason)
{
    _status = code;
    _reason = reason;
    _body = "";
}

void HttpResponse::setStatus(int code, const std::string &reason)
{
    _status = code;
    _reason = reason;
}

int HttpResponse::status() const
{
    return _status;
}

const std::string &HttpResponse::reason() const
{
    return _reason;
}

void HttpResponse::addHeader(const std::string &k, const std::string &v)
{
    _headers.set(k, v);
}

std::string HttpResponse::header(const std::string &k) const
{
    return _headers.get(k);
}

bool HttpResponse::hasHeader(const std::string &k) const
{
    return _headers.get(k) != "";
}

const HttpHeaders &HttpResponse::headers() const
{
    return _headers;
}

void HttpResponse::setBody(const std::string &b)
{
    _body = b;
}

const std::string &HttpResponse::body() const
{
    return _body;
}
