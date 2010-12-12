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

        int cases = 0;
        int passes = 0;
        int fails = 0;
        int errors = 0;
        int unimplemented = 0;


        for (vector<TestSuite*>::iterator it = _suites.begin(); it != _suites.end(); ++it) {
            (*it)->run();
            std::cout << (*it)->status() << std::endl;
            cases += (*it)->caseCount();
            passes += (*it)->passCount();
            fails += (*it)->failCount();
            errors += (*it)->errorCount();
            unimplemented += (*it)->unimplementedCount();
        }

        cout << endl << endl << "All test runned with " << cases << " cases: " << passes << " passed, " << fails << " failed and " << errors << " errors, with " << unimplemented << " unimplemented ones." << endl << endl;
    }

}
