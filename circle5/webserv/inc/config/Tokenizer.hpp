#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <sstream>

enum TokenType {
    TOKEN_KEYWORD,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMICOLON,
    TOKEN_EOF
};

struct t_token {
    TokenType type;
    std::string value;
    size_t line;
};

class Tokenizer {
private:
    std::string input;
    size_t pos;
    size_t line;

    char peek() const;
    char get();
    void skipWhitespaceAndComments();
    std::string readWord();
    t_token nextToken();

public:
    Tokenizer(const std::string &src);

    std::vector<t_token> tokenizeAll();
};

#endif
