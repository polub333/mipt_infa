#ifndef SPHINX_H
#define SPHINX_H

#include <iostream>
#include "cat.h"

class Sphinx: public Cat
{
public:
    Sphinx();
    void Pet() override { std::cout << "Petting Persian Cat " << name << std::endl; }
};

#endif // SPHINX_H
