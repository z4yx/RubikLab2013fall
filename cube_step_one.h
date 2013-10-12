#ifndef CUBE_STEP_ONE_H_
#define CUBE_STEP_ONE_H_
#include <string>
#include <cstdlib>
#include "cube_turn.h"
#include <cassert>
#include <iostream>
class cube_step_one_position{
public:
	int x, y, z;
	cube_step_one_position(){
		x = y = z = -1;
	}
};

class cube_step_one{
private:
	static bool color_mid_of_edge(char a[3][3], char base){
		return a[0][1] == base || a[1][0] == base || a[1][2] == base || a[2][1] == base;
	}
	static bool color_floor_mid_of_edge(Cube &A, char base){
		return A.front[0][1] == base || A.left[0][1] == base ||
				A.right[0][1] == base || A.back[0][1] == base;
	}
	static std::string rotate_cross_down(Cube &A, int base){
		for (int i = 0; i < 4; i++){
			std::string tmp = "";
			if (i == 1) tmp = "d";
			if (i == 2) tmp = "dd";
			if (i == 3) tmp = "D";
			if (A.down[2][1] == base && A.front[0][1] == A.front[1][1]){
				A.Turn_F();
				A.Turn_F();
				return tmp + "FF";
			}
			if (A.down[1][2] == base && A.right[0][1] == A.right[1][1]){
				A.Turn_r();
				A.Turn_r();
				return tmp + "rr";
			}
			if (A.down[0][1] == base && A.back[0][1] == A.back[1][1]){
				A.Turn_b();
				A.Turn_b();
				return tmp + "bb";
			}
			if (A.down[1][0] == base && A.left[0][1] == A.left[1][1]){
				A.Turn_L();
				A.Turn_L();
				return tmp + "LL";
			}
			A.Turn_d();
		}
		std::cout << "rotate_cross_down_failed" << std::endl;
		exit(0);
	}
	static std::string rotate_cross_floor(Cube &A, int base){
		for (int i = 0; i < 4; i++){
			std::string tmp = "";
			if (i == 1) tmp = "d";
			if (i == 2) tmp = "dd";
			if (i == 3) tmp = "D";
			if (A.right[0][1] == base && A.right[1][1] == A.down[1][2]){
				A.Turn_D();
				A.Turn_F();
				A.Turn_r();
				A.Turn_f();
				return tmp + "DFrf";
			}
			if (A.front[0][1] == base && A.front[1][1] == A.down[2][1]){
				A.Turn_D();
				A.Turn_L();
				A.Turn_f();
				A.Turn_l();
				return tmp + "DLfl";
			}
			if (A.left[0][1] == base && A.left[1][1] == A.down[1][0]){
				A.Turn_D();
				A.Turn_B();
				A.Turn_l();
				A.Turn_b();
				return tmp + "DBlb";
			}
			if (A.back[0][1] == base && A.back[1][1] == A.down[0][1]){
				A.Turn_D();
				A.Turn_R();
				A.Turn_b();
				A.Turn_r();
				return tmp + "DRbr";
			}
			A.Turn_d();
		}
		std::cout << "rotate_cross_floor_failed" << std::endl;
		exit(0);
	}
	static std::string rotate_cross_fix(Cube &A, int base){
		if (A.front[2][1] == base){
			A.Turn_f();
			A.Turn_f();
			return "ff";
		}
		if (A.left[2][1] == base){
			A.Turn_L();
			A.Turn_L();
			return "LL";
		}
		if (A.back[2][1] == base){
			A.Turn_B();
			A.Turn_B();
			return "BB";
		}
		if (A.right[2][1] == base){
			A.Turn_r();
			A.Turn_r();
			return "rr";
		}
		if (A.front[1][2] == base || A.right[1][0] == base){
			A.Turn_R();
			A.Turn_D();
			A.Turn_r();
			return "RDr";
		}
		if (A.back[1][0] == base || A.right[1][2] == base){
			A.Turn_r();
			A.Turn_D();
			A.Turn_R();
			return "rDR";
		}

		if (A.front[1][0] == base || A.left[1][2] == base){
			A.Turn_l();
			A.Turn_D();
			A.Turn_L();
			return "lDL";
		}
		if (A.back[1][2] == base || A.left[1][0] == base){
			A.Turn_L();
			A.Turn_D();
			A.Turn_l();
			return "LDl";
		}
		if (A.up[0][1] == base && A.front[2][1] != A.front[1][1]){
			A.Turn_f();
			return "f";
		}
		if (A.up[1][0] == base && A.left[2][1] != A.left[1][1]){
			A.Turn_L();
			return "L";
		}
		if (A.up[1][2] == base && A.right[2][1] != A.right[2][1]){
			A.Turn_r();
			return "r";
		}
		if (A.up[2][1] == base && A.back[2][1] != A.back[1][1]){
			A.Turn_b();
			return "b";
		}
		std::cout << "rotate_cross_between failed" << std::endl;
		exit(0);
	}
	static std::string get_cross(Cube &A){
		std::string step = "";
		char base = A.up[1][1];
		while (A.up[0][1] != base || A.up[1][0] != base ||
				A.up[1][2] != base || A.up[2][1] != base||
				A.front[2][1] != A.front[1][1] ||
				A.back[2][1] != A.back[1][1] ||
				A.left[2][1] != A.left[1][1] ||
				A.right[2][1] != A.right[1][1]){
			if (color_mid_of_edge(A.down, base)){
				step += rotate_cross_down(A, base);
			}
			else if (color_floor_mid_of_edge(A, base)){
				step += rotate_cross_floor(A, base);
			}
			else step += rotate_cross_fix(A, base);
		}
		A.Turn_y();
		A.Turn_y();
		return step + "yy";
	}
	static std::string get_corner(Cube A){
		std::string step;

		bool flag = 1;
		while (flag){
			flag = 0;


		}

		return step;
	}
public:
	static std::string step_one_solver(Cube A){
		std::string step = "";

		step += get_cross(A);
		step += get_corner(A);
		return step;
	}
};


#endif /* CUBE_STEP_ONE_H_ */
