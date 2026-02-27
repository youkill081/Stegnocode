//
// Created by Roumite on 27/02/2026.
//

#pragma once

#include <optional>
#include <string>

#include "Observable.h"

struct Crop
{
    uint16_t x, y, w, h;
};

enum FileBaseType
{
    SUBTEXTURE_TYPE,
    FILE_TYPE
};

class FileBase : public Observable
{
public:
    virtual ~FileBase() = default;

    virtual const std::string& get_path() = 0;
    virtual FileBaseType get_file_type() = 0;
    virtual std::optional<Crop> get_crop() const { return std::nullopt; }
};
