#ifndef LEXICO_H
#define LEXICO_H

#include <stdio.h>
#include <ctype.h>

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define PUNTO 2
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define FLO_LIT 13
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

FILE *in_fp, *fopen();

class Lexico
{
    public:
        int charClass;
        char lexeme [100];
        char nextChar;
        int lexLen;
        int token;
        int nextToken;

        Lexico();
        int lookup(char ch);
        void addChar();
        void getChar();
        void getNonBlank();
        int lex();
        virtual ~Lexico();
    private:
};

#endif // LEXICO_H
