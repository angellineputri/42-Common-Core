#include "../inc/FormUtils.hpp"

std::map<std::string, std::string> parsePostData(const std::string &body) {
    std::map<std::string, std::string> data;
    std::stringstream ss(body);
    std::string item;

    while (std::getline(ss, item, '&')) {
        size_t pos = item.find('=');
        if (pos != std::string::npos) {
            std::string key = item.substr(0, pos);
            std::string value = item.substr(pos + 1);

            std::replace(value.begin(), value.end(), '+', ' ');

            data[key] = value;
        }
    }
    return data;
}

bool parse_multipart(const std::string &body, const std::string &boundary, FormFile &outFile) {
    std::string sep = "--" + boundary;
    size_t pos = body.find(sep);
    if (pos == std::string::npos) return false;

    pos += sep.size() + 2;

    size_t headerEnd = body.find("\r\n\r\n", pos);
    if (headerEnd == std::string::npos) return false;

    std::string headers = body.substr(pos, headerEnd - pos);

    size_t fnPos = headers.find("filename=\"");
    if (fnPos == std::string::npos) return false;

    size_t fnStart = fnPos + 10;
    size_t fnEnd = headers.find("\"", fnStart);
    if (fnEnd == std::string::npos) return false;

    outFile.filename = headers.substr(fnStart, fnEnd - fnStart);

    size_t namePos = headers.find("name=\"");
    if (namePos != std::string::npos) {
        size_t nameStart = namePos + 6;
        size_t nameEnd = headers.find("\"", nameStart);
        if (nameEnd != std::string::npos)
            outFile.name = headers.substr(nameStart, nameEnd - nameStart);
    }

    size_t contentStart = headerEnd + 4;
    size_t contentEnd = body.find(sep, contentStart);
    if (contentEnd == std::string::npos) contentEnd = body.size();
    if (contentEnd >= 2) contentEnd -= 2;

    outFile.content = body.substr(contentStart, contentEnd - contentStart);
    return true;
}
