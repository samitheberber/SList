#include "iterator_tests.h"

IteratorTests::IteratorTests() : TestDriver::TestSuite("IteratorTests")
{
    add(new IteratorFromEmptyList());
    add(new IteratorFromOneSizeSList());
    add(new IteratorFromMoreThanOneSizeSList());
}

IteratorFromEmptyList::IteratorFromEmptyList() : TestDriver::TestCase("IteratorFromEmptyList")
{
}

IteratorFromOneSizeSList::IteratorFromOneSizeSList() : TestDriver::TestCase("IteratorFromOneSizeSList")
{
}

IteratorFromMoreThanOneSizeSList::IteratorFromMoreThanOneSizeSList() : TestDriver::TestCase("IteratorFromMoreThanOneSizeSList")
{
}

void IteratorFromEmptyList::run()
{
    SList newList;
    SList::iterator it = newList.begin();
    checkFalse(it != newList.end());
}

void IteratorFromOneSizeSList::run()
{
    SList newList;
    std::string str = "foobar";
    newList.push_front(str);

    SList::iterator it = newList.begin(); 

    checkTrue(it != newList.end());
    checkEquals((*it), str);

    ++it;
    checkFalse(it != newList.end());
}

void IteratorFromMoreThanOneSizeSList::run()
{
    SList newList;
    std::string str1 = "foobar";
    std::string str2 = "barfoo";
    std::string str3 = "barbaz";
    newList.push_front(str1);
    newList.push_front(str2);
    newList.push_front(str3);

    SList::iterator it = newList.begin(); 

    checkTrue(it != newList.end());
    checkEquals((*it), str3);

    ++it;
    checkTrue(it != newList.end());
    checkEquals((*it), str2);

    ++it;
    checkTrue(it != newList.end());
    checkEquals((*it), str1);

    ++it;
    checkFalse(it != newList.end());
}