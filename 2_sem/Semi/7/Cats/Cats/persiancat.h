#ifndef PERSIANCAT_H
#define PERSIANCAT_H

#include <iostream>
#include "cat.h"

class PersianCat: public Cat
{
public:
    PersianCat();
    void Pet() override { std::cout << "Petting Persian Cat " << name << std::endl;}
};

#endif // PERSIANCAT_H
