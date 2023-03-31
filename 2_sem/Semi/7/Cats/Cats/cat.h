#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "feline.h"

class Cat: public Feline
{
public:
    Cat();
    void virtual Pet() = 0;
    void Feed(const std::string& meal) override { std::cout << "Cat feeded by " << meal << std::endl;}
};

#endif // CAT_H
