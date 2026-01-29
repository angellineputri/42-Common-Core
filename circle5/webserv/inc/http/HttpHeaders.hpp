#ifndef HTTP_HEADERS_HPP
#define HTTP_HEADERS_HPP

#include <map>
#include <string>

class HttpHeaders {
    public:
        typedef std::map<std::string, std::string> Map;

        const Map &map() const;
        void set(const std::string &k, const std::string &v);
        std::string get(const std::string &k) const;

    private:
        Map _h;
};

#endif
