#ifndef RESPONSE_WRITER_HPP
#define RESPONSE_WRITER_HPP

#include <string>
#include <ctime>
#include <cstdio>
#include "http/HttpResponse.hpp"

std::string ft_to_string(int n);

class ResponseWriter {
    private:
        static std::string rfc1123Now();
        static std::string itoa10(int n);
        static std::string utoa10_size(size_t n);

    public:
        static std::string serialize(const HttpResponse &r, bool keepAlive);
};

#endif
