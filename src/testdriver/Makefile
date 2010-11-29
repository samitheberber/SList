CXXFLAGS = -pedantic -Wall -Werror -Wextra
CXX      = g++

DIRS = . test

testdriver_unittests = ../../bin/testdriver_unittests

objects = $(patsubst %.cpp,%.o, $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp)))

dep = $(objects:.o=.d)
dep := $(sort $(dep))

all: $(testdriver_unittests) testsuite

$(testdriver_unittests): $(objects)
	$(CXX) $^ -o $@

testsuite:; $(testdriver_unittests)

$(dep): %.d: %.cpp
	$(CXX) -MT "$(@:.d=.o) $@" -MM $(CXXFLAGS) $< > $@

clean:
	$(RM) $(testdriver_unittests) $(objects) $(dep)

ifneq ($(MAKECMDGOALS),clean)
  include $(dep)
endif
