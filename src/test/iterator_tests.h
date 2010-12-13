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

class ConstIteratorFromEmptyList: public TestDriver::TestCase
{
    public:
        ConstIteratorFromEmptyList();
        void run();
};

class ConstIteratorFromOneSizeSList: public TestDriver::TestCase
{
    public:
        ConstIteratorFromOneSizeSList();
        void run();
};

class ConstIteratorFromMoreThanOneSizeSList: public TestDriver::TestCase
{
    public:
        ConstIteratorFromMoreThanOneSizeSList();
        void run();
};

class ReverseWithEmptyList: public TestDriver::TestCase
{
    public:
        ReverseWithEmptyList();
        void run();
};

class ReverseWithMoreThanOneNode: public TestDriver::TestCase
{
    public:
        ReverseWithMoreThanOneNode();
        void run();
};

class IteratorTests: public TestDriver::TestSuite
{
    public:
        IteratorTests();
};

#endif
