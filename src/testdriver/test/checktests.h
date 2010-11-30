#include "../testdriver.h"

class CheckSame: public TestDriver::TestCase
{
    public:
        CheckSame() : TestDriver::TestCase("check_same") {};
        void run();
};

class CheckTests: public TestDriver::TestSuite
{
    public:
        CheckTests() : TestDriver::TestSuite("CheckTests") {
            add(new CheckSame());
        };
};
