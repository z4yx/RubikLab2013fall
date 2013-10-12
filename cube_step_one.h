#ifndef CUBE_STEP_ONE_H_
#define CUBE_STEP_ONE_H_
#include <string>
#include "cube_turn.h"

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
	static std::string rotate_cross_up(Cube &A, int base){
		std::string step = "";
		if (A.up[0][1] == base){
		}
		else if (A.up[1][0] == base){
			A.Turn_U();
			step += "U";
		}
		else if (A.up[1][2] == base){
			A.Turn_u();
			step += "u";
		}
		else{
			A.Turn_u();
			A.Turn_u();
			step += "uu";
		}

		if (A.down[2][1] != base){
			A.Turn_f();
			A.Turn_f();
			step += "ff";
		}
		else if (A.down[1][0] != base){
			A.Turn_u();
			A.Turn_L();
			A.Turn_L();
			step += "uLL";
		}
		else if (A.down[1][2] != base){
			A.Turn_U();
			A.Turn_r();
			A.Turn_r();
			step += "Urr";
		}
		else{
			A.Turn_D();
			A.Turn_D();
			A.Turn_f();
			A.Turn_f();
			step += "DDff";
		}
		return step;
	}
	static std::string rotate_cross_front(Cube &A, int base){
		std::string step = "";

		if (A.front[0][1] == base){
			A.Turn_F();
			step += "F";
			if (A.down[1][2] != base){
				A.Turn_R();
				step += "R";
			}
			else if (A.down[2][1] != base){
				A.Turn_d();
				A.Turn_R();
				step += "dR";
			}
			else if (A.down[0][1] != base){
				A.Turn_D();
				A.Turn_R();
				step += "DR";
			}
			else{
				A.Turn_D();
				A.Turn_D();
				A.Turn_R();
				step += "DDR";
			}
		}
		else if (A.front[1][0] == base){
			if (A.down[1][0] != base){
				A.Turn_l();
				step += "l";
			}
			else if (A.down[2][1] != base){
				A.Turn_D();
				A.Turn_l();
				step += "Dl";
			}
			else if (A.down[0][1] != base){
				A.Turn_d();
				A.Turn_l();
				step += "dl";
			}
			else{
				A.Turn_D();
				A.Turn_D();
				A.Turn_l();
				step += "DDl";
			}
		}
		else if (A.front[1][2] == base){
			if (A.down[1][2] != base){
				A.Turn_R();
				step += "R";
			}
			else if (A.down[2][1] != base){
				A.Turn_d();
				A.Turn_R();
				step += "dR";
			}
			else if (A.down[0][1] != base){
				A.Turn_D();
				A.Turn_R();
				step += "DR";
			}
			else{
				A.Turn_D();
				A.Turn_D();
				A.Turn_R();
				step += "DDR";
			}
		}
		else{
			if (A.down[2][1] != base){
				A.Turn_f();
				step += "f";
			}
			else if (A.down[1][0] != base){
				A.Turn_d();
				A.Turn_f();
				step += "df";
			}
			else if (A.down[1][2] != base){
				A.Turn_D();
				A.Turn_f();
				step += "Df";
			}
			else{
				A.Turn_d();
				A.Turn_d();
				A.Turn_f();
				step += "ddf";
			}

			if (A.down[1][2] != base){
				A.Turn_R();
				step += "R";
			}
			else if (A.down[2][1] != base){
				A.Turn_d();
				A.Turn_R();
				step += "dR";
			}
			else if (A.down[0][1] != base){
				A.Turn_D();
				A.Turn_R();
				step += "DR";
			}
			else{
				A.Turn_D();
				A.Turn_D();
				A.Turn_R();
				step += "DDR";
			}
		}
		return step;
	}
	static int get_cross_match_count(Cube &A){
		return (A.front[0][1] == A.front[1][1]) +
				(A.left[0][1] == A.left[1][1]) +
				(A.right[0][1] == A.right[1][1]) +
				(A.back[0][1] == A.back[1][1]);
	}
	static std::string get_cross(Cube &A){
		std::string step = "";
		char base = A.down[1][1];
		while (A.down[0][1] != base || A.down[1][0] != base ||
				A.down[1][2] != base || A.down[2][1] != base){

			if (color_mid_of_edge(A.front, base)){
				step += rotate_cross_front(A, base);
			}
			else if (color_mid_of_edge(A.left, base)){
				A.Turn_X();
				step += "X";
				step += rotate_cross_front(A, base);
			}
			else if (color_mid_of_edge(A.right, base)){
				A.Turn_x();
				step += "x";
				step += rotate_cross_front(A, base);
			}
			else if (color_mid_of_edge(A.back, base)){
				A.Turn_x();
				A.Turn_x();
				step += "xx";
				step += rotate_cross_front(A, base);
			}
			else if (color_mid_of_edge(A.up, base))
				step += rotate_cross_up(A, base);
		}

		if (get_cross_match_count(A) == 4)
			return step;
		if (get_cross_match_count(A) == 0){
			Cube B = A;
			B.Turn_d();
			if (get_cross_match_count(B) == 4){
				A = B;
				return step + "d";
			}
			B.Turn_d();
			if (get_cross_match_count(B) == 4){
				A = B;
				return step + "dd";
			}
			B.Turn_d();
			if (get_cross_match_count(B) == 4){
				A = B;
				return step + "D";
			}
		}
		if (A.front[0][1] == A.front[1][1]){
			A.Turn_X();
			step += "X";
		}
		A.Turn_L();
		A.Turn_L();
		A.Turn_r();
		A.Turn_r();
		A.Turn_d();
		A.Turn_d();
		A.Turn_L();
		A.Turn_L();
		A.Turn_r();
		A.Turn_r();
		return step + "LLrrddLLrr";
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
