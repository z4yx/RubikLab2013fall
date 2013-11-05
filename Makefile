UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LINK_PYTHON := -lpython2.7 -L/usr/lib/python2.7
endif
ifeq ($(UNAME_S),Darwin)
    LINK_PYTHON := -framework Python
endif

SOURCE=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SOURCE))

all: cube.so
%.o: %.cpp
	g++ -fpic -Wall -c $< -o $@ -I/usr/include/python2.7
cube.so: $(OBJS)
	g++ -shared -o cube.so $(OBJS) $(LINK_PYTHON)