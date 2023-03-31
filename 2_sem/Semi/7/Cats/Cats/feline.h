#ifndef FELINE_H
#define FELINE_H

#include <string>

class Feline
{
public:
    Feline();
    void SetName(std::string _name) { name = _name; }
    const std::string GetName() { return name; }
    virtual void Feed(const std::string& meal) = 0;
protected:
    std::string name;
};

#endif // FELINE_H
