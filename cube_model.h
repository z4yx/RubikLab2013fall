#ifndef CUBE_MODEL_H_
#define CUBE_MODEL_H_

class Cube
{
	void Swap_Face(char a[][3], char b[][3]);
	void Rotate_Face(char x[][3]);
	void Rotate_Face_r(char x[][3]);
public:
	char front[3][3],back[3][3],left[3][3],right[3][3],up[3][3],down[3][3];

	void Turn_R();
	void Turn_r();

	void Turn_L();
	void Turn_l();
	
	void Turn_U();
	void Turn_u();
	
	void Turn_D();
	void Turn_d();
	
	void Turn_F();
	void Turn_f();
	
	void Turn_B();
	void Turn_b();
	
	void Turn_X();
	void Turn_x();
	
	void Turn_Y();
	void Turn_y();
	
	void Turn_Z();
	void Turn_z();
	
	void Turn_P();
	void Turn_p();
	
	void Turn_Q();
	void Turn_q();
	
	void Turn_W();
	void Turn_w();

	void Apply(char op);
};

#endif /* CUBE_MODEL_H_ */