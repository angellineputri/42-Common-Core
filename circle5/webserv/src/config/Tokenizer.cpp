#include "Tokenizer.hpp"


Tokenizer::Tokenizer(const std::string &src) : input(src), pos(0), line(1) {}

char Tokenizer::peek() const {
    if (pos < input.size())
        return  (input[pos]);
    return ('\0');
}

char Tokenizer::get() {
    if (pos < input.size())
        return  (input[pos++]);
    return ('\0');
}

void Tokenizer::skipWhitespaceAndComments() {
    bool skipped = true;

    while (skipped) {
        skipped = false;

        while (std::isspace(peek())) {
            if (peek() == '\n')
                line++;
            get();
            skipped = true;
        }
    
        if (peek() == '#') {
            while (peek() != '\n' && peek() != '\0')
                get();
            skipped = true;
        }
    }
}

std::string Tokenizer::readWord() {
    std::string word;
    while (std::isalnum(peek()) ||
           peek() == '_' || peek() == '.' ||
           peek() == '/' || peek() == '-' ||
           peek() == ':')
    {
        word += get();
    }
    return word;
}

t_token Tokenizer::nextToken() {
    while (true) {
        skipWhitespaceAndComments();

        char c = peek();

        if (c == '\0') {
            t_token t;
            t.type = TOKEN_EOF;
            t.value = "";
            t.line = line;
            return t;
        }

        if (c == '{') {
            get();
            t_token t;
            t.type = TOKEN_LBRACE;
            t.value = "{";
            t.line = line;
            return t;
        }

        if (c == '}') {
            get();
            t_token t;
            t.type = TOKEN_RBRACE;
            t.value = "}";
            t.line = line;
            return t;
        }

        if (c == ';') {
            get();
            t_token t;
            t.type = TOKEN_SEMICOLON;
            t.value = ";";
            t.line = line;
            return t;
        }

        if (std::isalnum(c) || c == '/' || c == '.' || c == '_' || c == '-' || c == ':') {
            std::string word = readWord();
            t_token t;
            t.type = TOKEN_KEYWORD;
            t.value = word;
            t.line = line;
            return t;
        }

        std::ostringstream oss;
        oss << "Unexpected character at line " << line << ": " << c;
        throw std::runtime_error(oss.str());
    }
}

std::vector<t_token> Tokenizer::tokenizeAll() {
    std::vector<t_token> tokens;
    for (t_token tok = nextToken(); tok.type != TOKEN_EOF; tok = nextToken()) {
        tokens.push_back(tok);
    }
    return tokens;
}
