//
// Created by Roumite on 26/02/2026.
//

#pragma once

#include <set>
#include <vector>

#include "assembler/ISymbolSource.h"
#include "assembler/Linter.h"

namespace assembler
{
    struct ParsedLine;

    class LabelSet : public ISymbolSource
    {
    private:
        std::unordered_map<std::string, uint16_t> labels;
        uint64_t _current_instruction_idx = 0;

    public:
        static bool is_label(const ParsedLine &line);
        [[nodiscard]] SymbolSet get_symbols() const override;

        static LabelSet from_parsed_lines(const std::vector<ParsedLine> &lines, Linter &);
        [[nodiscard]] uint64_t get_number_of_instructions() const { return _current_instruction_idx; }
        void add_padding(uint64_t padding_size);

        void merge(const LabelSet &other, Linter& linter);
    };
}
