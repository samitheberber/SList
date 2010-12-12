#include "checktests.h"

#include <iostream>

void Pass::run()
{
    bool status = false;
    try {
        pass();
    } catch (TestDriver::TestPassedException&) {
        status = true;
    } catch (exception) {
        status = false;
    }

    try {
        pass("test passed");
    } catch (TestDriver::TestPassedException&) {
        status = true;
    } catch (exception) {
        status = false;
    }

    if (status)
        throw TestDriver::TestPassedException();
    else
        throw TestDriver::TestFailedException();
}

void Fail::run()
{
    bool status = false;
    try {
        fail();
    } catch (TestDriver::TestFailedException&) {
        status = true;
    } catch (exception) {
        status = false;
    }

    try {
        fail("test failed");
    } catch (TestDriver::TestFailedException&) {
        status = true;
    } catch (exception) {
        status = false;
    }

    if (status)
        throw TestDriver::TestPassedException();
    else
        throw TestDriver::TestFailedException();
}

void CheckSame::run()
{
    //checkSame(Object1,Object1);
    //checkSame(Object2,Object2);
    //checkSame(Object1,Object2);
    //checkSame(Object2,Object1);
    fail("not yet implemented");
}

void CheckNotSame::run()
{
    //checkNotSame(Object1,Object1);
    //checkNotSame(Object2,Object2);
    //checkNotSame(Object1,Object2);
    //checkNotSame(Object2,Object1);
    fail("not yet implemented");
}

void CheckTrue::run()
{
    checkTrue(true);
    bool fail = false;
    try {
        checkTrue(false);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}
    if (fail)
        throw TestDriver::TestFailedException("checkTrue(false) didn't fail");
}

void CheckFalse::run()
{
    checkFalse(false);
    bool fail = false;
    try {
        checkFalse(true);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}
    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");
}

void CheckEqualsBool::run()
{
    //checkEquals(true,true);
    //checkEquals(false,false);
    //checkEquals(true,false);
    //checkEquals(false,true);
    fail("not yet implemented");
}

void CheckNotEqualsBool::run()
{
    //checkNotEquals(true,true);
    //checkNotEquals(false,false);
    //checkNotEquals(true,false);
    //checkNotEquals(false,true);
    fail("not yet implemented");
}

void CheckEqualsString::run()
{
    //checkEquals('test string','test string');
    //checkEquals('test string 2','test string 2');
    //checkEquals('test string','test string 2');
    //checkEquals('test string 2','test string');
    fail("not yet implemented");
}

void CheckNotEqualsString::run()
{
    //checkNotEquals('test string','test string');
    //checkNotEquals('test string 2','test string 2');
    //checkNotEquals('test string','test string 2');
    //checkNotEquals('test string 2','test string');
    fail("not yet implemented");
}
