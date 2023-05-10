#include <iostream>
#include <thread>
#include <random>

#include <include/simmanager.h>
#include <include/util.h>

#include <include/animal.h>
#include <include/herbivorous.h>
#include <include/predator.h>

int main()
{
    srand(time(nullptr));

    using namespace std::chrono_literals;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    i16 width = 20;
    i16 height = 20;
    SimManager* mgr = new SimManager(width, height);

    i16 obstStartNum = 50;
    i16 herbStartNum = 15;
    i16 predStartNum = 20;

    mgr->RandomSpawn(obstStartNum, herbStartNum, predStartNum);

    while(true){
        mgr->Step();
        std::this_thread::sleep_for(250ms);
    }


    return 0;
}
