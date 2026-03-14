//
// Created by Roumite on 14/03/2026.
//

#include <iostream>

#include "lexer/Lexer.h"
#include "lexer/TextParser.h"

int main()
{
    compilator::TextParser parser = compilator::TextParser::from_file("C:/Users/Roumite/CLionProjects/stegnocode/steg/examples/test.steg");
    compilator::Lexer lexer(parser);

    try
    {
        lexer.compute();
        lexer.display();
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
