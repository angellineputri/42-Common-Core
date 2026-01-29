#ifndef FORMUTILS_HPP
#define FORMUTILS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

struct FormFile {
    std::string name;
    std::string filename;
    std::string content;
};

std::map<std::string, std::string>  parsePostData(const std::string &body);
bool    parse_multipart(const std::string &body, const std::string &boundary, FormFile &outFile);

#endif
