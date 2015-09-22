#ifndef SINTACTICO_H
#define SINTACTICO_H

#include "Lexico.h"

class Sintactico
{
    public:
        Lexico a;
        Sintactico();
        void error();
        void expr();
        void term();
        void factor();
        void ifstmt();
        virtual ~Sintactico();
    protected:
    private:
};

#endif // SINTACTICO_H
