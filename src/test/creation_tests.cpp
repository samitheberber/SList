#include "creation_tests.h"

#include <stdexcept>

CreationTests::CreationTests() : TestDriver::TestSuite("CreationTests")
{
    add(new FrontIsEmpty());
}

FrontIsEmpty::FrontIsEmpty() : TestDriver::TestCase("FrontIsEmpty")
{
}

void FrontIsEmpty::run()
{
    SList newList;
    try {
        string str = newList.front();
        fail();
    } catch (logic_error&) {
        pass();
    }
}
