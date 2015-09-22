#include "Sintactico.h"

Sintactico::Sintactico()
{
    //ctor
}

void Sintactico::error()
{
    printf("Error\n");
}

void Sintactico::expr()
{
    printf("Enter <expr>\n");
    term();
    while (a.nextToken == ADD_OP || a.nextToken == SUB_OP)
    {
        a.lex();
        term();
    }
    printf("Exit <expr>\n");
}

void Sintactico::term()
{
    printf("Enter <term>\n");
    factor();
    while (a.nextToken == MULT_OP || a.nextToken == DIV_OP)
    {
        a.lex();
        factor();
    }
    printf("Exit <term>\n");
}

void Sintactico::factor()
{
    printf("Enter <factor>\n");
    if (a.nextToken == IDENT || a.nextToken == INT_LIT)
        a.lex();
    else
    {
        if (a.nextToken == LEFT_PAREN)
        {
            a.lex();
            expr();
            if (a.nextToken == RIGHT_PAREN)
                a.lex();
            else
                error();
        }
        else
            error();
    }
    printf("Exit <factor>\n");
}
/*
void Sintactico::ifstmt()
{
    if (a.nextToken != IF_CODE)
        error();
    else
    {
        a.lex();
        if (a.nextToken != LEFT_PAREN)
            error();
        else
        {
            boolexpr();
            if (a.nextToken != RIGHT_PAREN)
                error();
            else
            {
                statement();
                if (a.nextToken == ELSE_CODE)
                {
                    lex();
                    statement();
                }
            }
        }
    }
}*/

Sintactico::~Sintactico()
{
    //dtor
}
