#ifndef H_ITERATOR_TESTS_H
#define H_ITERATOR_TESTS_H

#include "../testdriver/testdriver.h"

#include "../slist.h"

class IteratorFromEmptyList: public TestDriver::TestCase
{
    public:
        IteratorFromEmptyList();
        void run();
};

class IteratorFromOneSizeSList: public TestDriver::TestCase
{
    public:
        IteratorFromOneSizeSList();
        void run();
};

class IteratorFromMoreThanOneSizeSList: public TestDriver::TestCase
{
    public:
        IteratorFromMoreThanOneSizeSList();
        void run();
};

class IteratorTests: public TestDriver::TestSuite
{
    public:
        IteratorTests();
};

#endif
