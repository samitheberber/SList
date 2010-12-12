#ifndef H_TESTDRIVER_
#define H_TESTDRIVER_

#include <vector>
#include <string>
#include <exception>
#include <sstream>

using namespace std;

namespace TestDriver
{

    class TestCase
    {
        private:
            string _name;
            bool _implemented;
        protected:
            void pass();
            void pass(string);
            void fail();
            void fail(string);
            void checkSame(void*, void*);
            void checkNotSame(void*, void*);
            void checkTrue(bool);
            void checkFalse(bool);
            void checkEquals(bool,bool);
            void checkEquals(const string,const string);
            void checkNotEquals(bool,bool);
            void checkNotEquals(const string,const string);
        public:
            TestCase(string);
            virtual void run() = 0;
            const string getName();
            bool hasImplemented();
    };

    class TestSuite
    {
        private:
            int _passes;
            int _fails;
            int _errors;
            int _unimplemented;
            ostringstream _status;
            vector<TestCase*> _cases;
            string _name;
            void wip(const string);
            void passed(const string, const string);
            void passed(const string);
            void failed(const string, const string);
            void error(const string, const string);
        public:
            TestSuite(string);
            void run();
            void add(TestCase*);
            const string status();
            int passCount();
            int failCount();
            int errorCount();
            int unimplementedCount();
            int caseCount();
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
