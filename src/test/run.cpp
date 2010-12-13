#include "../testdriver/testdriver.h"

#include "creation_tests.h"
#include "insertion_tests.h"
#include "deletion_tests.h"

int main() {
    TestDriver::TestSuiteRunner runner;
    runner.add(new CreationTests());
    runner.add(new InsertionTests());
    runner.add(new DeletionTests());
    runner.run();
}
