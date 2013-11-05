#ifndef CUBE_STEP_ONE_H_
#define CUBE_STEP_ONE_H_

#include <string>
#include "cube_model.h"

class cube_step_one_position{
public:
	int x, y, z;
	cube_step_one_position(){
		x = y = z = -1;
	}
};

class cube_step_one{
private:
	static bool color_mid_of_edge(char a[3][3], char base);
	static bool color_floor_mid_of_edge(Cube &A, char base);
	static std::string rotate_cross_down(Cube &A, int base);
	static std::string rotate_cross_floor(Cube &A, int base);
	static std::string rotate_cross_fix(Cube &A, int base);
	static std::string get_cross(Cube &A);
	static bool color_corner_floor(Cube &A, int base);
	static std::string rotate_corner_floor(Cube &A, int base);
	static std::string rotate_corner_down(Cube &A, int base);
	static std::string rotate_corner_fix(Cube &A, int base);
	static std::string get_corner(Cube &A);
public:
	static std::string step_one_solver(Cube A);
};


#endif /* CUBE_STEP_ONE_H_ */
