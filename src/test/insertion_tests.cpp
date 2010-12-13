#include "insertion_tests.h"

InsertionTests::InsertionTests() : TestDriver::TestSuite("InsertionTests")
{
    add(new PushFront());
    add(new PushFrontTwice());
}

PushFront::PushFront() : TestDriver::TestCase("PushFront")
{
}

void PushFront::run()
{
    SList newList;
    string str = "foobar";
    newList.push_front(str);
    checkEquals(newList.front(), str);
}

PushFrontTwice::PushFrontTwice() : TestDriver::TestCase("PushFrontTwice")
{
}

void PushFrontTwice::run()
{
    SList newList;
    string str = "foobar";
    string str2 = "barbaz";
    newList.push_front(str);
    checkEquals(newList.front(), str);
    newList.push_front(str2);
    checkEquals(newList.front(), str2);
}
