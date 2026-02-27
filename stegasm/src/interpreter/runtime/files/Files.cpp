//
// Created by Roumite on 27/02/2026.
//

#include "Files.h"

#include "interpreter/exceptions.h"

descriptor Files::next_descriptor()
{
    while (_entries.contains(_current))
        _current++;
    return _current;
}

descriptor Files::open_file(const std::string& path)
{
    descriptor desc = next_descriptor();
    _entries.emplace(desc, File::open_file(path));
    return desc;
}

descriptor Files::create_file(const std::string& path)
{
    descriptor desc = next_descriptor();
    _entries.emplace(desc, File::create_empty_file(path));
    return desc;
}

void Files::push_file(descriptor desc, std::shared_ptr<FileBase> entry)
{
    _entries.emplace(desc, std::move(entry));
    if (desc >= _current)
        _current = desc + 1;
}

void Files::close_file(descriptor desc)
{
    _entries.erase(desc);
}

void Files::delete_file(descriptor desc)
{
    get_file(desc)->delete_file();
    _entries.erase(desc);
}

std::shared_ptr<FileBase> Files::operator[](descriptor desc)
{
    if (!_entries.contains(desc))
        throw FileError("Descriptor " + std::to_string(desc) + " not found !");
    return _entries.at(desc);
}

std::shared_ptr<File> Files::get_file(descriptor desc)
{
    auto file = std::dynamic_pointer_cast<File>((*this)[desc]);
    if (!file)
        throw FileError("Descriptor " + std::to_string(desc) + " is not a plain file !");
    return file;
}