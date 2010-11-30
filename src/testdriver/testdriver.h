#ifndef H_TESTDRIVER_
#define H_TESTDRIVER_

#include <vector>
#include <string>

using namespace std;

namespace TestDriver
{

    class TestCase
    {
        private:
            string _name;
        protected:
            // add test methods here
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
            std::vector<TestSuite*> _suites;
        public:
            void run();
            void add(TestSuite*);
    };

}

#endif
