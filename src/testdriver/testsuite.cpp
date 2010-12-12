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
        int passed = 0;
        int failed = 0;
        int error = 0;
        int count = 0;

        for (vector<TestCase*>::iterator it = _cases.begin(); it != _cases.end(); ++it) {
            try {
                try {
                    (*it)->run();
                    std::cout << "Test \"" << (*it)->getName() << "\": passed :)" << std::endl;
                } catch (TestPassedException& e) {
                    std::cout << "Test \"" << (*it)->getName() << "\": " << e.what() << " :)" << std::endl;
                }
                    passed++;
            } catch (TestFailedException& e) {
                std::cout << "Test \"" << (*it)->getName() << "\": " << e.what() << " :(" << std::endl;
                failed++;
            } catch (exception& e) {
                std::cout << "Test \"" << (*it)->getName() << "\" had following error: " << e.what() << " :!" << std::endl;
                error++;
            }
            count++;
        }

        std::cout << "Tested " << count << " cases: " << passed << " passed, " << failed << " failed and " << error << " errors." << std::endl;
    }

}
