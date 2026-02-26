//
// Created by Roumite on 23/02/2026.
//

#pragma once

#include <map>
#include <string>

#include "ByteBuffer.h"
#include "Observable.h"
#include "interpreter/exceptions.h"

using descriptor = uint16_t;

enum class FileType { EMPTY, NORMAL, BYTECODE };

class File final : public Observable
{
private:
    FileType _type;
    bool _data_was_read = false;
    bool _modified = false;
    std::string _path;
    std::string _extension;
    ByteBuffer _file_data{};

    void read_data_if_needed();

public:
    File(FileType type, const std::string& path) : _type(type), _path(path) {}
    File(const ByteBuffer& buffer, const std::string& extension)
        : _type(FileType::BYTECODE), _extension(extension),
          _data_was_read(true), _file_data(buffer) {}
    ~File();

    static std::shared_ptr<File> create_empty_file(const std::string& path)
        { return std::make_shared<File>(FileType::EMPTY, path); }

    static std::shared_ptr<File> open_file(const std::string& path)
        { return std::make_shared<File>(FileType::NORMAL, path); }

    static std::shared_ptr<File> from_bytecode(const ByteBuffer& buffer, const std::string& extension)
        { return std::make_shared<File>(buffer, extension); }

    [[nodiscard]] const std::string &get_path();

    void close();

    void save();
    void delete_file();

    void reset_cursor();
    void clear_data();

    uint8_t read_byte();
    uint16_t read_word();

    void append_byte(uint8_t byte);
    void append_word(uint16_t word);

    bool has_byte_remaining();
    bool has_word_remaining();
};

class Files
{
private:
    descriptor current_descriptor = 0;
    std::map<descriptor, std::shared_ptr<File>> files;
public:
    descriptor open_file(const std::string &path);
    descriptor create_file(const std::string &path);
    void push_file(uint16_t descriptor, std::shared_ptr<File> file);

    void close_file(descriptor descriptor);
    void delete_file(descriptor descriptor);

    std::shared_ptr<File> operator[](const descriptor &desc)
    {
        if (!this->files.contains(desc))
            throw FileError("File descriptor " + std::to_string(desc) + " not found !");
        return this->files.at(desc);
    }
};
