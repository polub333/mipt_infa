#ifndef LION_H
#define LION_H

#include <iostream>
#include <string>
#include "feline.h"

class Lion: public Feline
{
public:
    Lion();
    void Feed(const std::string& meal) override {
        std::cout<< "You feed a " << name << " by yourself" << std::endl; }
};

#endif // LION_H
