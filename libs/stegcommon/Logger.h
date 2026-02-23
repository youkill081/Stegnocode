//
// Created by Roumite on 17/02/2026.
//

#pragma once

#include <string>

class Logger
{
public:
    static void log(const std::string &message, const std::string &from="");
    static void log_uint32_as_bit(uint32_t number);
    static void log_uint64_as_bit(uint64_t number);
};
