#include "deletion_tests.h"

#include <stdexcept>

DeletionTests::DeletionTests() : TestDriver::TestSuite("DeletionTests")
{
    add(new PopFrontOfEmptyList());
    add(new PopFront());
    add(new PopFrontTwice());
    add(new DeleteAfterOnEmptyList());
    add(new DeleteAfterOnEmptyFollower());
    add(new DeleteAfter());
}

PopFrontOfEmptyList::PopFrontOfEmptyList() : TestDriver::TestCase("PopFrontOfEmptyList")
{
}

PopFront::PopFront() : TestDriver::TestCase("PopFront")
{
}

PopFrontTwice::PopFrontTwice() : TestDriver::TestCase("PopFrontTwice")
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

DeleteAfterOnEmptyList::DeleteAfterOnEmptyList() : TestDriver::TestCase("DeleteAfterOnEmptyList")
{
}

DeleteAfterOnEmptyFollower::DeleteAfterOnEmptyFollower() : TestDriver::TestCase("DeleteAfterOnEmptyFollower")
{
}

DeleteAfter::DeleteAfter() : TestDriver::TestCase("DeleteAfter")
{
}

void DeleteAfterOnEmptyList::run()
{
    SList newList;
    SList::iterator iter = newList.begin();
    try {
        newList.delete_after(iter);
    } catch(logic_error&) {
        pass();
    }
    fail();
}

void DeleteAfterOnEmptyFollower::run()
{
    SList newList;
    newList.push_front("foobar");
    SList::iterator iter = newList.begin();
    try {
        newList.delete_after(iter);
    } catch(logic_error&) {
        pass();
    }
    fail();
}

void DeleteAfter::run()
{
    SList newList;
    newList.push_front("foobar");
    newList.push_front("barfoo");
    newList.push_front("barbaz");
    SList::iterator iter = newList.begin();
    newList.delete_after(iter);
    checkEquals(newList.front(), "barbaz");
    newList.pop_front();
    checkEquals(newList.front(), "foobar");
}
