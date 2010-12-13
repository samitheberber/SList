CXXFLAGS = -pedantic -Wall -Werror -Wextra
CXX      = g++

all: clean build testing

DIRS = . testdriver

target_testdriver_unittests = ../bin/testdriver_unittests
target_slist_unittests = ../bin/slist_unittests

build: $(target_testdriver_unittests) $(target_slist_unittests)

objects_testdriver_unittests = $(patsubst %.cpp,%.o, $(foreach dir,$(DIRS) + testdriver/test,   $(wildcard $(dir)/*.cpp)))
objects_slist_unittests = $(patsubst %.cpp,%.o, $(foreach dir,$(DIRS) + test, $(wildcard $(dir)/*.cpp)))

dep = $(objects_testdriver_unittests:.o=.d)
dep += $(objects_slist_unittests:.o=.d)
dep := $(sort $(dep))

$(target_testdriver_unittests): $(objects_testdriver_unittests)
	$(CXX) $^ $(LDLIBS) -o $@

$(target_slist_unittests): $(objects_slist_unittests)
	$(CXX) $^ $(LDLIBS) -o $@

$(dep): %.d: %.cpp
	$(CXX) -MT "$(@:.d=.o) $@" -MM $(CXXFLAGS) $< > $@

testing:; $(target_testdriver_unittests) ; $(target_slist_unittests)

clean:
	$(RM) $(target_testdriver_unittests) $(target_slist_unittests) $(objects_testdriver_unittests) $(objects_slist_unittests) $(dep)

ifneq ($(MAKECMDGOALS),clean)
  include $(dep)
endif
