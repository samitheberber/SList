#ifndef H_TESTDRIVER_
#define H_TESTDRIVER_

#include <vector>
#include <string>
#include <exception>

using namespace std;

namespace TestDriver
{

    class TestCase
    {
        private:
            string _name;
        protected:
            void pass();
            void pass(string);
            void fail();
            void fail(string);
            void checkTrue(bool);
            void checkFalse(bool);
        public:
            TestCase(string);
            virtual void run() = 0;
            string getName();
    };

    class TestSuite
    {
        private:
            vector<TestCase*> _cases;
            string _name;
        public:
            TestSuite(string);
            void run();
            void add(TestCase*);
    };

    class TestSuiteRunner
    {
        private:
            vector<TestSuite*> _suites;
        public:
            void run();
            void add(TestSuite*);
    };

    class TestException: public exception
    {
        private:
            const char* _message;
        public:
            TestException(string);
            virtual const char* what() const throw();
    };

    class TestPassedException: public TestException
    {
        public:
            TestPassedException();
            TestPassedException(string);
    };

    class TestFailedException: public TestException
    {
        public:
            TestFailedException();
            TestFailedException(string);
    };

}

#endif
