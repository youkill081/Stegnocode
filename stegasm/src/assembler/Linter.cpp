//
// Created by Roumite on 26/02/2026.
//

#include "./Linter.h"

#include <iostream>

using namespace assembler;

Linter* Linter::current = nullptr;

void Linter::display_error(const LinterMessage& message)
{
    std::cout << "[ERROR] line " << message.line_number << ": " << message.message
                  << "\n  >> " << message.original_line << "\n";
}

void Linter::display_warning(const LinterMessage& message)
{
    std::cout << "[WARNING] line " << message.line_number << ": " << message.message
                  << "\n  >> " << message.original_line << "\n";
}

void Linter::error(const std::string &message, uint32_t token_index)
{
    throw LinterError{ message, token_index };
}

void Linter::inline_error(const std::string& message)
{
    auto final_message = LinterMessage{
        .line_number = 0,
        .original_line = "",
        .message = message,
        .token_index = 0
    };
    errors.push_back(final_message);
    display_error(final_message);
}

void Linter::warning(const ParsedLine &line, const std::string &message, uint32_t token_index)
{
    auto final_message = LinterMessage{
        .line_number = line.line_number,
        .original_line = line.original_line,
        .message = message,
        .token_index = token_index };
    current->warnings.push_back(final_message);
    display_warning(final_message);
}

void Linter::foreach(std::span<const ParsedLine> lines, const std::function<void(const ParsedLine&)> &callback)
{
    current = this;
    for (const auto &line : lines)
    {
        try { callback(line); }
        catch (const LinterError &e) {
            auto message = LinterMessage{ line.line_number, line.original_line, e.message, e.token_index };
            errors.push_back(message);
            display_error(message);
        }
    }
    current = nullptr;
}