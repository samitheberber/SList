#ifndef H_INSERTION_TESTS_H
#define H_INSERTION_TESTS_H

#include "../testdriver/testdriver.h"

#include "../slist.h"

class PushFront: public TestDriver::TestCase
{
    public:
        PushFront();
        void run();
};

class PushFrontTwice: public TestDriver::TestCase
{
    public:
        PushFrontTwice();
        void run();
};

class InsertAfterOnEmptySList: public TestDriver::TestCase
{
    public:
        InsertAfterOnEmptySList();
        void run();
};

class InsertAfter: public TestDriver::TestCase
{
    public:
        InsertAfter();
        void run();
};

class InsertionTests: public TestDriver::TestSuite
{
    public:
        InsertionTests();
};

#endif
