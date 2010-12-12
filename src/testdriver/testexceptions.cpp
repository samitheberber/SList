#include "testdriver.h"

namespace TestDriver
{

    TestException::TestException(string message)
    {
        _message = message.c_str();
    }

    const char* TestException::what() const throw()
    {
        return _message;
    }

    TestPassedException::TestPassedException(string message) : TestException(message)
    {
    }

    TestPassedException::TestPassedException() : TestException("passed")
    {
    }

    TestFailedException::TestFailedException(string message) : TestException(message)
    {
    }

    TestFailedException::TestFailedException() : TestException("failed")
    {
    }

}
