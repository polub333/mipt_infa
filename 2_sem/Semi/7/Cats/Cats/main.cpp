#include <iostream>

#include "feline.h"
#include "cat.h"
#include "lion.h"
#include "persiancat.h"
#include "sphinx.h"


using namespace std;

int main()
{
    Feline* f1 = new Lion();
    f1->SetName("BIGLION");
    f1->Feed("Some shit");

    Feline* f2 = new PersianCat();
    f2->SetName("ABOBA");
    f2->Feed("Milk");
    static_cast<Cat*>(f2)->Pet();

    Feline* f3 = new Sphinx();
    f3->SetName("Big Bob");
    dynamic_cast<Cat*>(f3)->Pet();

    return 0;
}
