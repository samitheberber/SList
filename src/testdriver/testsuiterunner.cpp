#include "testdriver.h"

#include <iostream>

using namespace std;

namespace TestDriver
{

    void TestSuiteRunner::add(TestSuite* suite)
    {
        _suites.push_back(suite);
    }

    void TestSuiteRunner::run()
    {
        std::cout << "Starting testsuite runner" << std::endl;

        for (vector<TestSuite*>::iterator it = _suites.begin(); it != _suites.end(); ++it) {
            (*it)->run();
        }
    }

}
