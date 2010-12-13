#include "insertion_tests.h"

#include <stdexcept>

InsertionTests::InsertionTests() : TestDriver::TestSuite("InsertionTests")
{
    add(new PushFront());
    add(new PushFrontTwice());
    add(new InsertAfterOnEmptySList());
    add(new InsertAfter());
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

InsertAfterOnEmptySList::InsertAfterOnEmptySList() : TestDriver::TestCase("InsertAfterOnEmptySList")
{
}

void InsertAfterOnEmptySList::run()
{
    SList newList;
    string str = "foobar";
    SList::iterator iter = newList.begin();
    try {
        newList.insert_after(iter, str);
    } catch (logic_error&) {
        pass();
    }
    fail();
}

InsertAfter::InsertAfter() : TestDriver::TestCase("InsertAfter")
{
}

void InsertAfter::run()
{
    SList newList;
    string str = "foobar";
    string str2 = "barbaz";
    newList.push_front(str);
    SList::iterator iter = newList.begin();
    newList.insert_after(iter, str2);
    ++iter;
    checkEquals(*iter, str2);
    checkEquals(newList.front(), str);
    newList.pop_front();
    checkEquals(newList.front(), str2);
}
