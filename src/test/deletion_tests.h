#ifndef H_DELETION_TESTS_H
#define H_DELETION_TESTS_H

#include "../testdriver/testdriver.h"

#include "../slist.h"

class PopFrontOfEmptyList: public TestDriver::TestCase
{
    public:
        PopFrontOfEmptyList();
        void run();
};

class PopFront: public TestDriver::TestCase
{
    public:
        PopFront();
        void run();
};

class PopFrontTwice: public TestDriver::TestCase
{
    public:
        PopFrontTwice();
        void run();
};

class DeleteAfter: public TestDriver::TestCase
{
    public:
        DeleteAfter();
        void run();
};

class DeletionTests: public TestDriver::TestSuite
{
    public:
        DeletionTests();
};

#endif
