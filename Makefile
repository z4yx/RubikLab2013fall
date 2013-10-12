all: cube.so
cube_wrapper.o: Cube_Turn.h cube_wrapper.cpp
	g++ -fpic -c cube_wrapper.cpp
cube.so: cube_wrapper.o
	g++ -shared -o cube.so cube_wrapper.o -framework Python