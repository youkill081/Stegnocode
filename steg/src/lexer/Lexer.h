//
// Created by Roumite on 14/03/2026.
//

#pragma once

#include "./lexer_definitions.h"
#include "TextParser.h"

#include <vector>

namespace compilator
{
    struct LexerToken
    {
        LexerTokensTypes type;
        std::string value;
        std::size_t line_number;
        std::size_t column_number;
    };

    class Lexer
    {
    private:
        bool _has_compute = false;
        TextParser &_parser;

        std::vector<LexerToken> _tokens{};

        std::size_t _browse_index = 0;

        LexerToken _parse_identifier_keyword(std::size_t line, std::size_t column) const;
        LexerToken _parse_string(std::size_t line, std::size_t column) const;
        LexerToken _parse_number(std::size_t line, std::size_t column) const;
        LexerToken _parse_symbol(std::size_t line, std::size_t column) const;

        LexerToken _compute_next_token() const;
        void _skip_space_and_comment() const;
    public:
        explicit Lexer(TextParser &parser) : _parser(parser) {}
        void compute();

        void init_browser();
        const LexerToken &get_next();
        bool has_next() const;

        const LexerToken &peek_x(std::size_t offset = 0);
        bool has_peek_x(std::size_t offset = 0) const;

        void display() const;
    };
}
