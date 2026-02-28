//
// Created by Roumite on 22/02/2026.
//

#include "CodeHandler.h"

#include "../../stegasm/src/assembler/Assembler.h"
#include "../../stegasm/src/interpreter/Vm.h"

std::string CodeHandler::get_name()
{
    return "code";
}

ByteBuffer CodeHandler::encode(const Parameters& parameters)
{
    if (parameters.get_parameters().empty())
        throw HandlerError("Missing file to encode !");

    assembler::Linter linter;
    ByteBuffer data = assembler::Assembler::assemble(parameters.get_parameters()[0], linter);
    if (linter.has_errors())
        throw HandlerError("Errors detected during assembly");
    return data;
}

void CodeHandler::decode(const Parameters& parameters, ByteBuffer& buffer)
{
    Vm::run(buffer);
}
