#include "../testdriver.h"

class Pass: public TestDriver::TestCase
{
    public:
        Pass() : TestDriver::TestCase("Pass") {};
        void run();
};

class Fail: public TestDriver::TestCase
{
    public:
        Fail() : TestDriver::TestCase("Fail") {};
        void run();
};

class CheckSame: public TestDriver::TestCase
{
    public:
        CheckSame() : TestDriver::TestCase("CheckSame") {};
        void run();
};

class CheckNotSame: public TestDriver::TestCase
{
    public:
        CheckNotSame() : TestDriver::TestCase("CheckNotSame") {};
        void run();
};

class CheckTrue: public TestDriver::TestCase
{
    public:
        CheckTrue() : TestDriver::TestCase("CheckTrue") {};
        void run();
};

class CheckFalse: public TestDriver::TestCase
{
    public:
        CheckFalse() : TestDriver::TestCase("CheckFalse") {};
        void run();
};

class CheckEqualsBool: public TestDriver::TestCase
{
    public:
        CheckEqualsBool() : TestDriver::TestCase("CheckEqualsBool") {};
        void run();
};

class CheckNotEqualsBool: public TestDriver::TestCase
{
    public:
        CheckNotEqualsBool() : TestDriver::TestCase("CheckNotEqualsBool") {};
        void run();
};

class CheckEqualsString: public TestDriver::TestCase
{
    public:
        CheckEqualsString() : TestDriver::TestCase("CheckEqualsString") {};
        void run();
};

class CheckNotEqualsString: public TestDriver::TestCase
{
    public:
        CheckNotEqualsString() : TestDriver::TestCase("CheckNotEqualsString") {};
        void run();
};

class CheckTests: public TestDriver::TestSuite
{
    public:
        CheckTests() : TestDriver::TestSuite("CheckTests") {
            add(new Pass());
            add(new Fail());
            add(new CheckSame());
            add(new CheckNotSame());
            add(new CheckTrue());
            add(new CheckFalse());
            add(new CheckEqualsBool());
            add(new CheckNotEqualsBool());
            add(new CheckEqualsString());
            add(new CheckNotEqualsString());
        };
};
