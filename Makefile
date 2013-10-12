all: cube.so
cube_wrapper.o: Cube_Turn.h cube_wrapper.cpp solve_2.cpp Third.h cube_step_one.h step_final.hpp
	g++ -fpic -c cube_wrapper.cpp
cube.so: cube_wrapper.o
	g++ -shared -o cube.so cube_wrapper.o -framework Python