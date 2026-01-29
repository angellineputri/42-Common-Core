#include "../../inc/http/RequestParser.hpp"

namespace {
    const size_t    MAX_LINE = 8192;
    const size_t MAX_HEADER_COUNT = 100;
    const size_t MAX_HEADER_TOTAL = 64 * 1024;
    const size_t MAX_BODY_TOTAL   = 10 * 1024 * 1024;
}

HttpRequestParser::HttpRequestParser() : _state(REQUEST_LINE), _buffer(), _needBodyBytes(0), _headerCount(0), _headerBytes(0), _bodyBytes(0), _sawContentLength(false), _contentLength(0)
{}

HttpRequestParser::Result
HttpRequestParser::feed(const char* data, size_t len, HttpRequest& outReq, std::string& outErr, size_t max_body_size)
{
    if (data && len)
        _buffer.append(data, len);
    outErr.clear();

    while (true) {
        switch (_state) {
            case REQUEST_LINE: {
                if (_buffer.size() > MAX_LINE) {
                    outErr = "Request line too long";
                    _state = ERR;
                    return ERROR;
                }
                std::string line;
                if (!consumeCRLFLine(line))
                    return INCOMPLETE;
                if (line.size() > MAX_LINE) {
                    outErr = "Request line too long";
                    _state = ERR;
                    return ERROR;
                }
                if (!parseRequestLine(line, outReq, outErr))
                {
                    _state = ERR;
                    return ERROR;
                }
                _state = HEADERS;
                break;
            }
            case HEADERS: {
                if (_buffer.size() > MAX_LINE)
                {
                    outErr = "Header line too long";
                    _state = ERR;
                    return ERROR;
                }
                std::string line;
                if (!consumeCRLFLine(line))
                    return INCOMPLETE;
                if (line.size() > MAX_LINE)
                {
                    outErr = "Header line too long";
                    _state = ERR;
                    return ERROR;
                }
                if (line.empty())
                {
                    _headerBytes += 2;
                    if (_headerBytes > MAX_HEADER_TOTAL) 
                    {
                            outErr = "Headers too large";
                            _state = ERR;
                            return ERROR;
                    }
                    if (!finishHeaders(outReq, outErr))
                    {
                        _state = ERR;
                        return ERROR;
                    }
                    _state = (_needBodyBytes > 0) ? BODY_CL : DONE;
                    break;
                }
                if (!parseHeaderLine(line, outReq, outErr))
                {
                    _state = ERR;
                    return ERROR;
                }
                break;
            }
            case BODY_CL: {
                if (_needBodyBytes == 0)
                {
                    _state = DONE;
                    break;
                }
                size_t take = _buffer.size();
                if (take > _needBodyBytes) take = _needBodyBytes;


                if (take)
                {
                    outReq.setBody(outReq.body() + _buffer.substr(0, take));
                    _buffer.erase(0, take);
                    _needBodyBytes -= take;
                    _bodyBytes += take;
                    if (_bodyBytes > max_body_size) 
                    {
                        outErr = "Body exceeds server limit";
                        _state = ERR; return ERROR;
                    }
                }

                if (_needBodyBytes > 0) return INCOMPLETE;

                _state = DONE;
                break;
            }
            case DONE: {
                return COMPLETE;
            }
            case ERR: {
                if (outErr.empty()) outErr = "parse error";
                return ERROR;
            }
        }
    }
    return INCOMPLETE;
}

void HttpRequestParser::reset() {
    _state = REQUEST_LINE;
    _buffer.clear();
    _needBodyBytes = 0;
    _headerCount = 0;
    _headerBytes = 0;
    _bodyBytes = 0;
    _sawContentLength = false;
    _contentLength = 0;
}

std::string HttpRequestParser::trim(const std::string &s) {
    size_t a = 0, b = s.size();
    while (a < b && (s[a] == ' ' || s[a] == '\t' || s[a] == '\r' || s[a] == '\n'))
        ++a;
    while (b > a && (s[b-1] == ' ' || s[b-1] == '\t' || s[b-1] == '\r' || s[b-1] == '\n'))
        --b;
    return s.substr(a, b - a);
}

std::string HttpRequestParser::toLower(const std::string &s) {
    std::string t = s;
    for (size_t i = 0; i < t.size(); ++i)
        if (t[i] >= 'A' && t[i] <= 'Z') 
            t[i] = char(t[i]-'A'+'a');
    return t;
}

bool HttpRequestParser::consumeCRLFLine(std::string &outLine) 
{   
    std::string::size_type p = _buffer.find("\r\n");
        if (p == std::string::npos) 
            return false;
    outLine.assign(_buffer, 0, p);
    _buffer.erase(0, p + 2);
    return true;
}

bool    HttpRequestParser::parseRequestLine(const std::string &line, HttpRequest &req, std::string &err)
{
    std::string m, u, v;
    std::string::size_type a = 0, s1 = line.find(' ', a);
    if (s1 == std::string::npos)
    {
        err = "Bad request-line (missing token)";
        return false;
    }
    m = line.substr(a, s1 -a);

    a = s1 + 1;
    std::string::size_type s2 = line.find(' ', a);
        if (s2 == std::string::npos)
    {
        err = "Bad request-line (missing HTTP version)";
        return false;
    }
    u = line.substr(a, s2 -a);

    v = line.substr(s2 + 1);

    if (m.empty() || u.empty() || v.empty())
    {
        err = "Empty token in request-line";
        return false;
    }
    if (!(v == "HTTP/1.0" || v == "HTTP/1.1"))
    {
        err = "Unsupported HTTP version";
        return false;
    }
    for (size_t i = 0; i < m.size(); ++i) 
    {
        char c = m[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        {
            err = "Invalid method token";
            return false;
        }
    }

    req.setMethod(m);
    req.setTarget(u);
    req.setVersion(v);
    return true;
}

bool HttpRequestParser::parseHeaderLine(const std::string& line, HttpRequest& req, std::string& err) 
{
    _headerBytes += line.size() + 2;
    if (_headerBytes > MAX_HEADER_TOTAL) 
    {
        err = "Headers too large";
        return false;
    }

    std::string::size_type col = line.find(':');
    if (col == std::string::npos)
    {
        err = "Header missing ':'";
        return false;
    }

    std::string name = toLower(trim(line.substr(0, col)));
    std::string value = trim(line.substr(col + 1));
    if (name.empty())
    {
        err = "Empty header name";
        return false;
    }

    _headerCount++;
    if (_headerCount > MAX_HEADER_COUNT)
    {
        err = "Too many headers";
        return false;
    }

    if (name == "content-length") 
    {
        unsigned long long n = 0;
        if (value.empty()) 
        { 
            err = "Invalid Content-Length";
            return false; 
        }
        for (size_t i = 0; i < value.size(); ++i)
        {
            char c = value[i];
            if (c < '0' || c > '9')
            {
                err = "Invalid Content-Length";
                return false;
            }
            n = n * 10ull + (unsigned long long)(c - '0');
            if (n > (unsigned long long)MAX_BODY_TOTAL)
            {
                err = "Body exceeds server limit";
                return false;
            }
            if (n > (unsigned long long)(~(size_t)0))
            {
                err = "Content-Length too large";
                return false;
            }
        }
        if (_sawContentLength && (size_t)n != _contentLength) 
        {
            err = "Conflicting Content-Length";
            return false;
        }
        _sawContentLength = true;
        _contentLength    = (size_t)n; 
    }
    req.setHeader(name, value);
    return true;
}

bool HttpRequestParser::finishHeaders(HttpRequest& req, std::string& err)
{
    if (req.version() == "HTTP/1.1" && req.header("host").empty())
    {
        err = "HTTP/1.1 requires Host";
        return false;
    }

    const std::string te = toLower(req.header("transfer-encoding"));
    if (!te.empty() && te.find("chunked") != std::string::npos) {
        err = "Chunked transfer-encoding not supported";
        return false;
    }

    if (_sawContentLength) {
        _needBodyBytes = _contentLength;
        _bodyBytes = 0;
        return true;
    }

    _needBodyBytes = 0;
    _bodyBytes = 0;
    return true;
}
