//
// Created by Roumite on 14/03/2026.
//

#include <vector>
#include <iostream>

#include "ast/ASTProgramNode.h"
#include "lexer/Lexer.h"
#include "lexer/TextParser.h"

int main()
{
    compilator::TextParser parser = compilator::TextParser::from_file(
        "C:/Users/Roumite/CLionProjects/stegnocode/steg/examples/test.steg");
    compilator::Lexer lexer(parser);

    try
    {
        lexer.compute();

using namespace  compilator;

        std::vector<std::unique_ptr<ASTVariableProgramNode>> globals;
        globals.push_back(std::make_unique<ASTVariableProgramNode>(
            "g_counter",
            std::make_unique<ASTTypeNode>(ASTTypeNode::UINT32),
            std::make_unique<ASTLiteralExpressionNode>("0", std::make_unique<ASTTypeNode>(ASTTypeNode::UINT32)) // = 0
        ));

        // --- 2. Construction d'une fonction complexe ---
        // Signature: function test_recursive(n: INT32, factor: UINT32) -> INT32
        std::vector<std::unique_ptr<ASTParameterProgramNode>> params;
        params.push_back(
            std::make_unique<ASTParameterProgramNode>("n", std::make_unique<ASTTypeNode>(ASTTypeNode::INT32)));
        params.push_back(
            std::make_unique<ASTParameterProgramNode>("factor", std::make_unique<ASTTypeNode>(ASTTypeNode::UINT32)));

        // -- Corps de la fonction --
        std::vector<std::unique_ptr<ASTStatementNode>> body_content;

        // Une boucle FOR : for(i = 0; i < n; i += 1)
        auto for_init = std::make_unique<ASTAssignExpressionStatement>(
            std::make_unique<ASTIdentifierExpressionNode>("i"),
            ASTAssignExpressionStatement::ASSIGN,
            std::make_unique<ASTLiteralExpressionNode>("0", std::make_unique<ASTTypeNode>(ASTTypeNode::UINT32))
        );

        auto for_cond = std::make_unique<ASTBinaryExpressionNode>(
            std::make_unique<ASTIdentifierExpressionNode>("i"),
            std::make_unique<ASTIdentifierExpressionNode>("n"),
            ASTBinaryExpressionNode::binaryOperationType::COMPARISON_LESS
        );

        auto for_post = std::make_unique<ASTAssignExpressionStatement>(
            std::make_unique<ASTIdentifierExpressionNode>("i"),
            ASTAssignExpressionStatement::assignmentType::ASSIGN,
            std::make_unique<ASTLiteralExpressionNode>("1", std::make_unique<ASTTypeNode>(ASTTypeNode::INT32))
        );

        // Contenu du FOR : un IF/ELSE
        std::vector<std::unique_ptr<ASTStatementNode>> if_body_stmts;
        if_body_stmts.push_back(std::make_unique<ASTContinueStatement>());

        auto if_stmt = std::make_unique<ASTBlockIfStatementNode>(
            std::make_unique<ASTBinaryExpressionNode>(
                std::make_unique<ASTIdentifierExpressionNode>("i"),
                std::make_unique<ASTLiteralExpressionNode>("10", std::make_unique<ASTTypeNode>(ASTTypeNode::UINT16)),
                ASTBinaryExpressionNode::binaryOperationType::COMPARISON_EQUAL
            ),
            std::make_unique<ASTBlockStatementNode>(std::move(if_body_stmts)),
            std::make_unique<ASTBreakStatement>() // else break
        );

        body_content.push_back(std::make_unique<ASTForStatementNode>(
            std::move(for_init), std::move(for_cond), std::move(for_post), std::move(if_stmt)
        ));

        // Une expression mathématique récursive : return (n + 1) * (factor / 2)
        auto complex_math = std::make_unique<ASTBinaryExpressionNode>(
            std::make_unique<ASTBinaryExpressionNode>(
                std::make_unique<ASTIdentifierExpressionNode>("n"),
                std::make_unique<ASTLiteralExpressionNode>("1", std::make_unique<ASTTypeNode>(ASTTypeNode::INT16)),
                ASTBinaryExpressionNode::ADDITION
            ),
            std::make_unique<ASTBinaryExpressionNode>(
                std::make_unique<ASTIdentifierExpressionNode>("factor"),
                std::make_unique<ASTLiteralExpressionNode>("2", std::make_unique<ASTTypeNode>(ASTTypeNode::INT8)),
                ASTBinaryExpressionNode::DIVISION
            ),
            ASTBinaryExpressionNode::MULTIPLICATION
        );

        body_content.push_back(std::make_unique<ASTReturnStatement>(std::move(complex_math)));

        // Finalisation de la fonction
        auto test_func = std::make_unique<ASTFunctionProgramNode>(
            "test_recursive",
            std::move(params),
            std::make_unique<ASTTypeNode>(ASTTypeNode::INT32),
            std::make_unique<ASTBlockStatementNode>(std::move(body_content)),
            true // exported
        );

        // --- 3. Assemblage final dans le programme ---
        std::vector<std::unique_ptr<ASTFunctionProgramNode>> functions;
        functions.push_back(std::move(test_func));

        ASTMainProgramNode(std::move(functions), std::move(globals)).display(0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
