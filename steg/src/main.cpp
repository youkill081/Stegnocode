//
// Created by Roumite on 14/03/2026.
//

#include <iostream>

#include "lexer/Lexer.h"
#include "lexer/TextParser.h"

int main()
{
    lexer::TextParser parser = lexer::TextParser::from_file("C:/Users/Roumite/CLionProjects/stegnocode/steg/examples/test.steg");
    lexer::Lexer lexer(parser);

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
