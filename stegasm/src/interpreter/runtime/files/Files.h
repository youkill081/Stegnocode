//
// Created by Roumite on 27/02/2026.
//

#pragma once

#include <map>
#include <memory>
#include <string>

#include "File.h"
#include "FileBase.h"

using descriptor = uint16_t;

class Files
{
private:
    descriptor _current = 0;
    std::map<descriptor, std::shared_ptr<FileBase>> _entries;

    descriptor next_descriptor();

public:
    descriptor open_file(const std::string& path);
    descriptor create_file(const std::string& path);
    void push_file(descriptor desc, std::shared_ptr<FileBase> entry);

    void close_file(descriptor desc);
    void delete_file(descriptor desc);

    std::shared_ptr<FileBase> operator[](descriptor desc);
    std::shared_ptr<File> get_file(descriptor desc);
};