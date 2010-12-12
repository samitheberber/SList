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

    void TestCase::pass()
    {
        throw TestPassedException();
    }

    void TestCase::pass(string message)
    {
        throw TestPassedException(message);
    }

    void TestCase::fail()
    {
        throw TestFailedException();
    }

    void TestCase::fail(string message)
    {
        throw TestFailedException(message);
    }

    void TestCase::checkTrue(bool value) {
        if (!value)
            throw TestFailedException("checkTrue(bool) got false");
    }

    void TestCase::checkFalse(bool value) {
        if (value)
            throw TestFailedException("checkFalse(bool) got true");
    }

}
