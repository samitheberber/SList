#include "testdriver.h"

#include <iostream>

namespace TestDriver
{

    TestSuite::TestSuite(string name)
    {
        _name = name;
    }

    void TestSuite::add(TestCase* tcase)
    {
        _cases.push_back(tcase);
    }

    void TestSuite::run()
    {
        std::cout << "Running " << _name << " tests..." << std::endl;

        for (vector<TestCase*>::iterator it = _cases.begin(); it != _cases.end(); ++it) {
            std::cout << "Case: " << (*it)->getName() << std::endl;
            (*it)->run();
        }
    }

}
