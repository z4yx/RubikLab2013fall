#include "cube_model.h"
#include <algorithm>

void Cube::Swap_Face(char a[][3], char b[][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::swap(a[i][j], b[i][j]);
		}
	}
}
void Cube::Rotate_Face(char face[][3])
{
	char tmp;
	
	//角块旋转
	tmp = face[0][0];
	face[0][0] = face[2][0];
	face[2][0] = face[2][2];
	face[2][2] = face[0][2];
	face[0][2] = tmp;

	//棱块旋转
	tmp = face[0][1];
	face[0][1] = face[1][0];
	face[1][0] = face[2][1];
	face[2][1] = face[1][2];
	face[1][2] = tmp;
}
void Cube::Rotate_Face_r(char face[][3])
{
	Rotate_Face(face);
	Rotate_Face(face);
	Rotate_Face(face);
}

void Cube::Turn_R()
{
	char a[3];

	a[0]=up[0][2];
	a[1]=up[1][2];
	a[2]=up[2][2];

	up[0][2]=back[2][0];
	up[1][2]=back[1][0];
	up[2][2]=back[0][0];

	back[2][0]=down[0][2];
	back[1][0]=down[1][2];
	back[0][0]=down[2][2];

	down[0][2]=front[0][2];
	down[1][2]=front[1][2];
	down[2][2]=front[2][2];

	front[0][2]=a[0];
	front[1][2]=a[1];
	front[2][2]=a[2];
	
	Rotate_Face(right);
}
void Cube::Turn_r()
{
	Turn_R();
	Turn_R();
	Turn_R();
}

void Cube::Turn_L()
{
	char a[3];
	
	a[0]=up[0][0];
	a[1]=up[1][0];
	a[2]=up[2][0];
	
	up[0][0]=front[0][0];
	up[1][0]=front[1][0];
	up[2][0]=front[2][0];

	front[0][0]=down[0][0];
	front[1][0]=down[1][0];
	front[2][0]=down[2][0];

	down[0][0]=back[2][2];
	down[1][0]=back[1][2];
	down[2][0]=back[0][2];

	back[2][2]=a[0];
	back[1][2]=a[1];
	back[0][2]=a[2];
	
	Rotate_Face(left);
}
void Cube::Turn_l()
{
	Turn_L();
	Turn_L();
	Turn_L();
}

void Cube::Turn_U()
{
	char a[3];

	a[0]=front[2][0];
	a[1]=front[2][1];
	a[2]=front[2][2];

	front[2][0]=left[2][0];
	front[2][1]=left[2][1];
	front[2][2]=left[2][2];

	left[2][0]=back[2][0];
	left[2][1]=back[2][1];
	left[2][2]=back[2][2];

	back[2][0]=right[2][0];
	back[2][1]=right[2][1];
	back[2][2]=right[2][2];

	right[2][0]=a[0];
	right[2][1]=a[1];
	right[2][2]=a[2];

	Rotate_Face(up);
}
void Cube::Turn_u()
{
	Turn_U();
	Turn_U();
	Turn_U();
}

void Cube::Turn_D()
{
	char a[3];

	a[0]=front[0][0];
	a[1]=front[0][1];
	a[2]=front[0][2];

	front[0][0]=right[0][0];
	front[0][1]=right[0][1];
	front[0][2]=right[0][2];

	right[0][0]=back[0][0];
	right[0][1]=back[0][1];
	right[0][2]=back[0][2];

	back[0][0]=left[0][0];
	back[0][1]=left[0][1];
	back[0][2]=left[0][2];

	left[0][0]=a[0];
	left[0][1]=a[1];
	left[0][2]=a[2];
	
	Rotate_Face(down);
}
void Cube::Turn_d()
{
	Turn_D();
	Turn_D();
	Turn_D();
}

void Cube::Turn_F()
{
	char a[3];

	a[0]=up[0][0];
	a[1]=up[0][1];
	a[2]=up[0][2];

	up[0][0]=right[2][0];
	up[0][1]=right[1][0];
	up[0][2]=right[0][0];

	right[2][0]=down[2][2];
	right[1][0]=down[2][1];
	right[0][0]=down[2][0];

	down[2][2]=left[0][2];
	down[2][1]=left[1][2];
	down[2][0]=left[2][2];

	left[0][2]=a[0];
	left[1][2]=a[1];
	left[2][2]=a[2];

	Rotate_Face(front);
}
void Cube::Turn_f()
{
	Turn_F();
	Turn_F();
	Turn_F();
}

void Cube::Turn_B()
{
	char a[3];

	a[0]=up[2][0];
	a[1]=up[2][1];
	a[2]=up[2][2];

	up[2][0]=left[0][0];
	up[2][1]=left[1][0];
	up[2][2]=left[2][0];

	left[0][0]=down[0][2];
	left[1][0]=down[0][1];
	left[2][0]=down[0][0];

	down[0][2]=right[2][2];
	down[0][1]=right[1][2];
	down[0][0]=right[0][2];

	right[2][2]=a[0];
	right[1][2]=a[1];
	right[0][2]=a[2];

	Rotate_Face(back);
}
void Cube::Turn_b()
{
	Turn_B();
	Turn_B();
	Turn_B();
}

void Cube::Turn_X()
{
	Swap_Face(front, left);
	Swap_Face(left, back);
	Swap_Face(back, right);

	Rotate_Face(up);
	Rotate_Face_r(down);
}
void Cube::Turn_x()
{
	Turn_X();
	Turn_X();
	Turn_X();
}

void Cube::Turn_Y()
{
	char a[3];

	Turn_F();

	a[0]=up[1][0];
	a[1]=up[1][1];
	a[2]=up[1][2];

	up[1][0]=right[2][1];
	up[1][1]=right[1][1];
	up[1][2]=right[0][1];

	right[2][1]=down[1][2];
	right[1][1]=down[1][1];
	right[0][1]=down[1][0];

	down[1][2]=left[0][1];
	down[1][1]=left[1][1];
	down[1][0]=left[2][1];

	left[0][1]=a[0];
	left[1][1]=a[1];
	left[2][1]=a[2];
	
	Turn_b();
}
void Cube::Turn_y()
{
	Turn_Y();
	Turn_Y();
	Turn_Y();
}

void Cube::Turn_Z()
{
	char a[3];

	Turn_R();
	Turn_l();

	a[0]=up[0][1];
	a[1]=up[1][1];
	a[2]=up[2][1];

	up[0][1]=back[2][1];
	up[1][1]=back[1][1];
	up[2][1]=back[0][1];

	back[2][1]=down[0][1];
	back[1][1]=down[1][1];
	back[0][1]=down[2][1];

	down[0][1]=front[0][1];
	down[1][1]=front[1][1];
	down[2][1]=front[2][1];

	front[0][1]=a[0];
	front[1][1]=a[1];
	front[2][1]=a[2];
}
void Cube::Turn_z()
{
	Turn_Z();
	Turn_Z();
	Turn_Z();
}

void Cube::Turn_P()
{
	Turn_u();
	Turn_D();
	Turn_X();
}
void Cube::Turn_p()
{
	Turn_P();
	Turn_P();
	Turn_P();
}

void Cube::Turn_Q()
{
	Turn_f();
	Turn_B();
	Turn_Y();
}
void Cube::Turn_q()
{
	Turn_Q();
	Turn_Q();
	Turn_Q();
}

void Cube::Turn_W()
{
	Turn_L();
	Turn_r();
	Turn_Z();
}
void Cube::Turn_w()
{
	Turn_W();
	Turn_W();
	Turn_W();
}

void Cube::Apply(char op)
{
	switch(op) {
		case 'u':
			Turn_u();
			break;
		case 'U':
			Turn_U();
			break;
		case 'D':
			Turn_D();
			break;
		case 'd':
			Turn_d();
			break;
		case 'l':
			Turn_l();
			break;
		case 'L':
			Turn_L();
			break;
		case 'r':
			Turn_r();
			break;
		case 'R':
			Turn_R();
			break;
		case 'f':
			Turn_f();
			break;
		case 'F':
			Turn_F();
			break;
		case 'b':
			Turn_b();
			break;
		case 'B':
			Turn_B();
			break;
		case 'x':
			Turn_x();
			break;
		case 'X':
			Turn_X();
			break;
		case 'y':
			Turn_y();
			break;
		case 'Y':
			Turn_Y();
			break;
		case 'z':
			Turn_z();
			break;
		case 'Z':
			Turn_Z();
			break;
		case 'p':
			Turn_p();
			break;
		case 'P':
			Turn_P();
			break;
		case 'q':
			Turn_q();
			break;
		case 'Q':
			Turn_Q();
			break;
		case 'w':
			Turn_w();
			break;
		case 'W':
			Turn_W();
			break;
	}
}