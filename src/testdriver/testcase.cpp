#include "testdriver.h"

#include <string>
#include <iostream>

using namespace std;

namespace TestDriver
{

    TestCase::TestCase(string name)
    {
        _name = name;
    }

    string TestCase::getName()
    {
        return _name;
    }

}
