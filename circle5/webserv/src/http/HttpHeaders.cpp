#include "../../inc/http/HttpHeaders.hpp"

const HttpHeaders::Map &HttpHeaders::map() const {
    return _h;
}

void HttpHeaders::set(const std::string &k, const std::string &v) {
    _h[k] = v;
}

std::string HttpHeaders::get(const std::string &k) const {
    Map::const_iterator it = _h.find(k);
    return it == _h.end() ? std::string() : it->second;
}
