#include "deletion_tests.h"

#include <stdexcept>

DeletionTests::DeletionTests() : TestDriver::TestSuite("DeletionTests")
{
    add(new PopFrontOfEmptyList());
    add(new PopFront());
}

PopFrontOfEmptyList::PopFrontOfEmptyList() : TestDriver::TestCase("PopFrontOfEmptyList")
{
}

PopFront::PopFront() : TestDriver::TestCase("PopFront")
{
}

PopFrontTwice::PopFrontTwice() : TestDriver::TestCase("PopFront")
{
}

void PopFrontOfEmptyList::run()
{
    try {
        SList newList;
        newList.pop_front();
        fail("no logic_error thrown");
    } catch (logic_error&) {
        pass();
    }
}

void PopFront::run()
{
    SList newList;
    string str = "foobar";
    newList.push_front(str);
    checkEquals(newList.front(), str);
    newList.pop_front();
    try {
        string str2 = newList.front();
        fail("no logic_error thrown");
    } catch (logic_error&) {
        pass();
    }
}

void PopFrontTwice::run()
{
    SList newList;
    string str = "foobar";
    string str2 = "barbaz";
    newList.push_front(str);
    checkEquals(newList.front(), str);
    newList.push_front(str2);
    checkEquals(newList.front(), str2);
    newList.pop_front();
    checkEquals(newList.front(), str);
    newList.pop_front();
    try {
        string str3 = newList.front();
        fail("no logic_error thrown");
    } catch (logic_error&) {
        pass();
    }
}
