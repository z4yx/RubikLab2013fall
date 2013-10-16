UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LINK_PYTHON := -lpython2.7 -L/usr/lib/python2.7
endif
ifeq ($(UNAME_S),Darwin)
    LINK_PYTHON := -framework Python
endif
all: cube.so
cube_wrapper.o: Cube_Turn.h cube_wrapper.cpp solve_2.cpp Third.h cube_step_one.h step_final.hpp
	g++ -fpic -c cube_wrapper.cpp -I/usr/include/python2.7
cube.so: cube_wrapper.o
	g++ -shared -o cube.so cube_wrapper.o $(LINK_PYTHON)