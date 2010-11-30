#include "../testdriver.h"

#include "checktests.h"

int main() {
    TestDriver::TestSuiteRunner runner;
    runner.add(new CheckTests());
    runner.run();
}
