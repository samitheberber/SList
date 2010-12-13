#include "creation_tests.h"

#include <stdexcept>

CreationTests::CreationTests() : TestDriver::TestSuite("CreationTests")
{
    add(new FrontIsEmpty());
    add(new SwapTwoLists());
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

SwapTwoLists::SwapTwoLists() : TestDriver::TestCase("SwapTwoLists")
{
}

void SwapTwoLists::run()
{
    SList newList;
    SList otherList;
    std::string str1 = "foo";
    std::string str2 = "bar";
    std::string str3 = "baz";
    std::string str4 = "far";
    std::string str5 = "faz";
    newList.push_front(str1);
    newList.push_front(str2);
    newList.push_front(str3);
    otherList.push_front(str4);
    otherList.push_front(str5);
    newList.swap(otherList);

    checkEquals(newList.front(), str5);
    newList.pop_front();
    checkEquals(newList.front(), str4);

    checkEquals(otherList.front(), str3);
    otherList.pop_front();
    checkEquals(otherList.front(), str2);
    otherList.pop_front();
    checkEquals(otherList.front(), str1);
}
