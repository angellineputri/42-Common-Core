#include "../../inc/http/ResponseWriter.hpp"

static void addHeader(std::string& out, const std::string& k, const std::string& v) {
    out += k; out += ": "; out += v; out += "\r\n";
}

std::string ResponseWriter::itoa10(int n) {
    return ft_to_string(n);
}

std::string ResponseWriter::utoa10_size(size_t n) {
    char buf[32];

#if defined(__LP64__) || defined(_WIN64)
    std::snprintf(buf, sizeof(buf), "%lu", (unsigned long)n);
#else
    std::snprintf(buf, sizeof(buf), "%u", (unsigned int)n);
#endif
    return std::string(buf);
}

std::string ResponseWriter::rfc1123Now() {
    char buf[64];
    std::time_t t = std::time(0);
#if defined(_WIN32)
    std::tm g; gmtime_s(&g, &t);
    std::strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S GMT", &g);
#else
    std::tm* pg = std::gmtime(&t);
    std::strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S GMT", pg);
#endif
    return std::string(buf);
}

std::string ResponseWriter::serialize(const HttpResponse& r, bool keepAlive) {
    std::string out;

    out += "HTTP/1.1 ";
    out += itoa10(r.status());
    out += " ";
    out += r.reason();
    out += "\r\n";

    addHeader(out, "Date",    rfc1123Now());
    addHeader(out, "Server",  "webserv/0.1");
    addHeader(out, "Connection", keepAlive ? "keep-alive" : "close");

    if (!r.hasHeader("content-length")) {
        addHeader(out, "Content-Length", utoa10_size(r.body().size()));
    }

    out += "\r\n";

    out += r.body();
    return out;
}
