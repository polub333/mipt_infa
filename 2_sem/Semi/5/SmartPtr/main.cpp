#include <iostream>

#include "uniqueptr.h"
#include "sharedptr.h"

int main()
{
    /*
    UniquePtr<int> up1(new int(10));
    std::cout << *up1 << std::endl;
    UniquePtr<int> up2 = std::move(up1);
    UniquePtr<int> up3;
    up3 = std::move(up2);
    std::cout << *up3 << std::endl;
    UniquePtr<double> up4(new double(0.1));
    UniquePtr<double> up5(std::move(up4));
    std::cout << *up5 << std::endl;
    std::cout << *up4 << std::endl;
    */

    SharedPtr<int> sp1(new int(10));
    SharedPtr<int> sp2(sp1);
    std::cout << *sp1 << " " << *sp2 << std::endl;
    SharedPtr<int> sp3 = std::move(sp1);
    std::cout << *sp3 << std::endl;
    std::cout << *sp2 << std::endl;
    {
        SharedPtr<int> sp4 = std::move(sp3);
    }

    return 0;
}
