#include "../testdriver/testdriver.h"

#include "../slist.h"

class FrontIsEmpty: public TestDriver::TestCase
{
    public:
        FrontIsEmpty();
        void run();
};

class SwapTwoLists: public TestDriver::TestCase
{
    public:
        SwapTwoLists();
        void run();
};

class CreationTests: public TestDriver::TestSuite
{
    public:
        CreationTests();
};
