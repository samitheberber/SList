#include "testdriver.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

namespace TestDriver
{

    TestCase::TestCase(string name)
    {
        _name = name;
        _implemented = false;
    }

    const string TestCase::getName()
    {
        return _name;
    }

    bool TestCase::hasImplemented()
    {
        return _implemented;
    }

    void TestCase::pass()
    {
        _implemented = true;
        throw TestPassedException("pass()");
    }

    void TestCase::pass(string message)
    {
        _implemented = true;
        throw TestPassedException(message);
    }

    void TestCase::fail()
    {
        _implemented = true;
        throw TestFailedException("fail()");
    }

    void TestCase::fail(string message)
    {
        _implemented = true;
        throw TestFailedException(message);
    }

    void TestCase::checkSame(void* actual, void* expected)
    {
        _implemented = true;
        if (actual != expected)
            throw TestFailedException("checkSame() failed");
    }

    void TestCase::checkNotSame(void* actual, void* expected)
    {
        _implemented = true;
        if (actual == expected)
            throw TestFailedException("checkNotSame() failed");
    }

    void TestCase::checkTrue(bool condition)
    {
        _implemented = true;
        if (!condition)
            throw TestFailedException("checkTrue(bool) got false");
    }

    void TestCase::checkFalse(bool condition)
    {
        _implemented = true;
        if (condition)
            throw TestFailedException("checkFalse(bool) got true");
    }

    void TestCase::checkEquals(bool actual, bool expected)
    {
        _implemented = true;
        try {
            checkTrue(actual == expected);
        } catch (TestFailedException&) {
            ostringstream str; str << "checkEquals(bool,bool) failed with (" << ( (actual) ? "true" : "false") << "," << ((expected) ? "true" : "false") << ")";
            throw TestFailedException(str.str());
        }
    }

    void TestCase::checkEquals(const string actual, const string expected)
    {
        _implemented = true;
        if (actual != expected) {
            ostringstream str; str << "checkEquals(string,string) failed with (" << actual << "," << expected << ")";
            throw TestFailedException(str.str());
        }
    }

    void TestCase::checkNotEquals(bool actual, bool expected)
    {
        _implemented = true;
        try {
            checkFalse(actual == expected);
        } catch (TestFailedException&) {
            ostringstream str; str << "checkNotEquals(bool,bool) failed with (" << ( (actual) ? "true" : "false") << "," << ((expected) ? "true" : "false") << ")";
            throw TestFailedException(str.str());
        }
    }

    void TestCase::checkNotEquals(const string actual, const string expected)
    {
        _implemented = true;
        if (actual == expected) {
            ostringstream str; str << "checkEquals(string,string) failed with (" << actual << "," << expected << ")";
            throw TestFailedException(str.str());
        }
    }

}
