#include "../testdriver/testdriver.h"

#include "../slist.h"

class FrontIsEmpty: public TestDriver::TestCase
{
    public:
        FrontIsEmpty();
        void run();
};

class CreationTests: public TestDriver::TestSuite
{
    public:
        CreationTests();
};
