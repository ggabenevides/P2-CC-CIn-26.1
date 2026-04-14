#ifndef _QUADRADO_H
#define _QUADRADO_H

#include "FiguraGeometrica.h"

class Quadrado : FiguraGeometrica {

    private:

        int lado;

    public:

        int get_lado() const {return this-> lado;}

        void set_lado(int lado) {this->lado = lado;}
};