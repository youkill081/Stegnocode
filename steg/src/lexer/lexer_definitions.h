//
// Created by Roumite on 14/03/2026.
//

#pragma once

#include <map>
#include <array>
#include <string_view>

namespace lexer
{
    enum LexerTokensTypes
    {
        TOKEN_KEYWORD,
        TOKEN_TYPE,
        TOKEN_BOOL,
        TOKEN_INTEGER,
        TOKEN_IDENTIFIER, // Variable identifier, for example
        TOKEN_COMPARISON,
        TOKEN_ASSIGNMENT,
        TOKEN_OPERATOR,
        TOKEN_PUNCTUATION,
        TOKEN_STRING,
        TOKEN_EOF // Automatically added by lexer at the end of the file
    };

    struct TokenEntry {
        std::string_view name;
        LexerTokensTypes type;
    };

    constexpr std::array KEYWORDS = {
        // Keywords
        TokenEntry{"fn", TOKEN_KEYWORD},
        TokenEntry{"if", TOKEN_KEYWORD},
        TokenEntry{"while", TOKEN_KEYWORD},
        TokenEntry{"return", TOKEN_KEYWORD},
        TokenEntry{"for", TOKEN_KEYWORD},
        TokenEntry{"export", TOKEN_KEYWORD},

        // Types
        TokenEntry{"uint8", TOKEN_TYPE},
        TokenEntry{"int8", TOKEN_TYPE},
        TokenEntry{"uint16", TOKEN_TYPE},
        TokenEntry{"int16", TOKEN_TYPE},
        TokenEntry{"uint32", TOKEN_TYPE},
        TokenEntry{"int32", TOKEN_TYPE},
        TokenEntry{"bool", TOKEN_TYPE},
        TokenEntry{"void", TOKEN_TYPE},

        // Literals
        TokenEntry{"true", TOKEN_BOOL},
        TokenEntry{"false", TOKEN_BOOL},

        // Assigment
        TokenEntry{"=", TOKEN_ASSIGNMENT},

        // Operator
        TokenEntry{"+", TOKEN_OPERATOR},
        TokenEntry{"-", TOKEN_OPERATOR},
        TokenEntry{"*", TOKEN_OPERATOR},
        TokenEntry{"/", TOKEN_OPERATOR},
        TokenEntry{"%", TOKEN_OPERATOR},
        TokenEntry{"!", TOKEN_OPERATOR},
        TokenEntry{"&", TOKEN_OPERATOR},
        TokenEntry{"#", TOKEN_OPERATOR},

        // Comparison
        TokenEntry{"==", TOKEN_COMPARISON},
        TokenEntry{"!=", TOKEN_COMPARISON},
        TokenEntry{"<", TOKEN_COMPARISON},
        TokenEntry{">", TOKEN_COMPARISON},
        TokenEntry{"<=", TOKEN_COMPARISON},
        TokenEntry{">=", TOKEN_COMPARISON},
        TokenEntry{"&&", TOKEN_COMPARISON},
        TokenEntry{"||", TOKEN_COMPARISON},

        // Punctuation
        TokenEntry{"(", TOKEN_PUNCTUATION},
        TokenEntry{")", TOKEN_PUNCTUATION},
        TokenEntry{"{", TOKEN_PUNCTUATION},
        TokenEntry{"}", TOKEN_PUNCTUATION},
        TokenEntry{"[", TOKEN_PUNCTUATION},
        TokenEntry{"]", TOKEN_PUNCTUATION},
        TokenEntry{",", TOKEN_PUNCTUATION},
        TokenEntry{";", TOKEN_PUNCTUATION},
        TokenEntry{"->", TOKEN_PUNCTUATION},
    };

    inline std::map<LexerTokensTypes, std::string_view> token_type_to_string = {
        {TOKEN_KEYWORD, "TOKEN_KEYWORD"},
        {TOKEN_TYPE, "TOKEN_TYPE"},
        {TOKEN_BOOL, "TOKEN_BOOL"},
        {TOKEN_INTEGER, "TOKEN_INTEGER"},
        {TOKEN_IDENTIFIER, "TOKEN_IDENTIFIER"},
        {TOKEN_COMPARISON, "TOKEN_COMPARISON"},
        {TOKEN_ASSIGNMENT, "TOKEN_ASSIGNMENT"},
        {TOKEN_OPERATOR, "TOKEN_OPERATOR"},
        {TOKEN_PUNCTUATION, "TOKEN_PUNCTUATION"},
        {TOKEN_STRING, "TOKEN_STRING"},
        {TOKEN_EOF, "TOKEN_EOF"}
    };
}