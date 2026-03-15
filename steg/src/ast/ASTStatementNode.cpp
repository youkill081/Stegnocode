//
// Created by Roumite on 14/03/2026.
//

#include "ASTStatementNode.h"

void compilator::ASTBlockStatementNode::display(std::size_t left_padding)
{
    display_name("Block", left_padding);

    for (auto &statement : statements)
    {
        statement->display(left_padding + 1);
    }
}

void compilator::ASTBlockIfStatementNode::display(std::size_t left_padding)
{
    display_name("If", left_padding);

    display_indent(left_padding);
    std::cout << "Condition" << std::endl;
    condition->display(left_padding + 1);

    if (false_statement) {
        display_indent(left_padding);
        std::cout << "Else" << std::endl;
        false_statement->display(left_padding + 2);
    }
}

void compilator::ASTWhileStatementNode::display(std::size_t left_padding)
{
    display_name("While", left_padding);

    display_indent(left_padding);
    std::cout << "Condition" << std::endl;
    condition->display(left_padding + 1);

    display_indent(left_padding);
    std::cout << "Body" << std::endl;
    body_statement->display(left_padding + 1);
}

void compilator::ASTForStatementNode::display(std::size_t left_padding)
{
    display_name("For", left_padding);

    display_indent(left_padding);
    std::cout << "Init" << std::endl;
    init_expression->display(left_padding + 1);

    display_indent(left_padding);
    std::cout << "Condition" << std::endl;
    condition_expression->display(left_padding + 1);

    display_indent(left_padding);
    std::cout << "Post" << std::endl;
    post_expression->display(left_padding + 1);

    display_indent(left_padding);
    std::cout << "Body" << std::endl;
    body_statement->display(left_padding + 1);
}

void compilator::ASTReturnStatement::display(std::size_t left_padding)
{
    display_name("Return", left_padding);

    if (expression)
    {
        expression->display(left_padding + 1);
    } else
    {
        display_indent(left_padding + 1);
        std::cout << "No return expression" << std::endl;
    }
}

void compilator::ASTBreakStatement::display(std::size_t left_padding)
{
    display_name("Break", left_padding);
}

void compilator::ASTContinueStatement::display(std::size_t left_padding)
{
    display_name("Continue", left_padding);
}

void compilator::ASTExpressionStatement::display(std::size_t left_padding)
{
    display_name("Expression", left_padding);
    expression->display(left_padding + 1);
}
