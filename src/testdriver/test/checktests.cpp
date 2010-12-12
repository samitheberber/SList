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
    string str1 = "foo";
    string str2 = "bar";
    checkSame(&str1,&str1);
    checkSame(&str2,&str2);

    bool fail = false;
    try {
        checkSame(&str1,&str2);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkSame() didn't fail");

    fail = false;
    try {
        checkSame(&str2,&str1);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkSame() didn't fail");
}

void CheckNotSame::run()
{
    string str1 = "foo";
    string str2 = "bar";

    bool fail = false;
    try {
        checkNotSame(&str1,&str1);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkNotSame() didn't fail");

    fail = false;
    try {
        checkNotSame(&str2,&str2);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkNotSame() didn't fail");

    checkNotSame(&str1,&str2);
    checkNotSame(&str2,&str1);
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
    checkEquals(true,true);
    checkEquals(false,false);

    bool fail = false;
    try {
        checkEquals(true,false);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");

    fail = false;
    try {
        checkEquals(false,true);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");
}

void CheckNotEqualsBool::run()
{
    bool fail = false;
    try {
        checkNotEquals(true,true);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");

    fail = false;
    try {
        checkNotEquals(false,false);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");

    checkNotEquals(true,false);
    checkNotEquals(false,true);
}

void CheckEqualsString::run()
{
    string str1 = "test string";
    string str2 = "test string 2";

    checkEquals(str1,str1);
    checkEquals(str2,str2);

    bool fail = false;
    try {
        checkEquals(str1,str2);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");

    fail = false;
    try {
        checkEquals(str2,str1);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");
}

void CheckNotEqualsString::run()
{
    string str1 = "test string";
    string str2 = "test string 2";

    bool fail = false;
    try {
        checkNotEquals(str1,str1);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");

    fail = false;
    try {
        checkNotEquals(str2,str2);
        fail = true;
    } catch (TestDriver::TestFailedException&) {}

    if (fail)
        throw TestDriver::TestFailedException("checkFalse(true) didn't fail");

    checkNotEquals(str1,str2);
    checkNotEquals(str2,str1);
}
