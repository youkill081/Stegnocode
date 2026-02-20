//
// Created by Roumite on 18/02/2026.
//

#pragma once
#include "IHander.h"

class FileHandler : public IHandler
{
private:
public:
    [[nodiscard]] std::string get_name() override;
    ByteBuffer encode(const Parameters& parameters) override;
    void decode(const Parameters& parameters, ByteBuffer& buffer) override;
};
