#include "testdriver.h"

using namespace std;

namespace TestDriver
{

    TestSuite::TestSuite(string name)
    {
        _name = name;
        _passes = 0;
        _fails = 0;
        _errors = 0;
        _unimplemented = 0;
    }

    void TestSuite::add(TestCase* tcase)
    {
        _cases.push_back(tcase);
    }

    void TestSuite::run()
    {
        for (vector<TestCase*>::iterator it = _cases.begin(); it != _cases.end(); ++it) {
            try {
                try {
                    (*it)->run();

                    if ( (*it)->hasImplemented() ) {
                        passed((*it)->getName());
                        _passes++;
                    } else {
                        wip((*it)->getName());
                        _unimplemented++;
                    }

                } catch (TestPassedException& e) {
                    passed((*it)->getName(), e.what());
                    _passes++;
                }
            } catch (TestFailedException& e) {
                failed((*it)->getName(), e.what());
                _fails++;
            } catch (exception& e) {
                error((*it)->getName(), e.what());
                _errors++;
            }
        }

    }

    void TestSuite::wip(const string name)
    {
        _status << "Test \"" << name << "\" not yet implemented!" << endl;
    }

    void TestSuite::passed(const string name)
    {
        passed(name, "passed");
    }

    void TestSuite::passed(const string name, const string message)
    {
        _status << "Test \"" << name << "\": " << message << " :)" << endl;
    }

    void TestSuite::failed(const string name, const string message)
    {
        _status << "Test \"" << name << "\": " << message << " :(" << endl;
    }

    void TestSuite::error(const string name, const string message)
    {
        _status << "Test \"" << name << "\" had following error: " << message << " :!" << endl;
    }

    const string TestSuite::status()
    {
        _status << endl << "Tested \"" << _name << "\" with " << _cases.size() << " cases: " << _passes << " passed, " << _fails << " failed, " << _errors << " errors and " << _unimplemented << " unimplemented ones." << endl;

        return _status.str();
    }

    int TestSuite::passCount()
    {
        return _passes;
    }
    
    int TestSuite::failCount()
    {
        return _fails;
    }

    int TestSuite::errorCount()
    {
        return _errors;
    }

    int TestSuite::unimplementedCount()
    {
        return _unimplemented;
    }

    int TestSuite::caseCount()
    {
        return _cases.size();
    }

}
