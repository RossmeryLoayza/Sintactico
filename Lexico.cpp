#include "Lexico.h"

Lexico::Lexico()
{
    if ((in_fp = fopen("front.in", "r")) == NULL)
        printf("ERROR - cannot open front.in \n");
    else
    {
        getChar();
        do {
             lex();
           }
        while (nextToken != EOF);
    }
}

/* lookup - a function to lookup operators and parentheses
            and return the token */
int Lexico::lookup(char ch)
{
    switch (ch)
    {
        case '(':
              addChar();
              nextToken = LEFT_PAREN;
              break;
        case ')':
              addChar();
              nextToken = RIGHT_PAREN;
              break;
        case '+':
              addChar();
              nextToken = ADD_OP;
              break;
        case '-':
              addChar();
              nextToken = SUB_OP;
              break;
        case '*':
              addChar();
              nextToken = MULT_OP;
              break;
        case '/':
              addChar();
              nextToken = DIV_OP;
              break;
        case '.':
              addChar();
              nextToken = PUNTO;
              break;
        default:
              addChar();
              nextToken = EOF;
              break;
    }
    return nextToken;
}

/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void Lexico::addChar()
{
    if (lexLen <= 98)
    {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    }
    else
        printf("Error - lexeme is too long \n");
}

/*****************************************************/
/* getChar - a function to get the next character of
             input and determine its character class */
void Lexico::getChar()
{
    if ((nextChar = getc(in_fp)) != EOF)
    {
        if (isalpha(nextChar))
            charClass = LETTER;
        else
        {
            if (isdigit(nextChar))
                charClass = DIGIT;
            else
            {
                if (nextChar == '.')
                    charClass = PUNTO;
                else
                    charClass = UNKNOWN;
            }
        }
    }
    else
        charClass = EOF;
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it
                 returns a non-whitespace character */
void Lexico::getNonBlank()
{
    while (isspace(nextChar))
        getChar();
}

int tmp = 0;

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic
         expressions */
int Lexico::lex()
{
    lexLen = 0;
    getNonBlank();
    switch (charClass)
    {
        /* Parse identifiers */
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT)
            {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;
        /* Parse integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT)
            {
                addChar();
                getChar();
            }
            if(charClass == PUNTO)
            {
                addChar();
                getChar();
                if (charClass == PUNTO || charClass == LETTER)
                {
                    nextToken = UNKNOWN;
                }
                while (charClass == DIGIT)
                {
                    addChar();
                    getChar();
                    tmp = 1;
                }
            }

            if(charClass == LETTER || charClass == PUNTO)
            {
                addChar();
                getChar();
                while (!isspace(nextChar))
                {
                    addChar();
                    getChar();
                }
            }

            if(nextToken != UNKNOWN)
            {
                if (tmp == 1)
                    nextToken = FLO_LIT;
                else
                    nextToken = INT_LIT;
            }
            break;

        case PUNTO:
            addChar();
            getChar();
            while(charClass == DIGIT)
            {
                addChar();
                getChar();
            }

            if(charClass == LETTER)
            {
                addChar();
                getChar();
                while (!isspace(nextChar)) {
                    addChar();
                    getChar();
                }
                nextToken = UNKNOWN;
            }
            else
                nextToken = FLO_LIT;
            break;
        /* Parentheses and operators */
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;
        /* EOF */
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    } /* End of switch */

      printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
}  /* End of function lex */

Lexico::~Lexico()
{
    //dtor
}
