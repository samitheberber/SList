#include "checktests.h"

#include <iostream>

void CheckSame::run()
{
    std::cout << "test check_same(true,true)" << std::endl;
    std::cout << "test check_same(true,false)" << std::endl;
    std::cout << "test check_same(false,true)" << std::endl;
    std::cout << "test check_same(false,false)" << std::endl;
}
