#ifndef CUBETURN_H
#define CUBETURN_H
#include<stdio.h>
#include<string.h>
#include<math.h>
struct Cube
{
	char front[3][3],back[3][3],left[3][3],right[3][3],up[3][3],down[3][3];
	
public:
	int swap(char &a,char &b)
	{
		char c;
		c=a;a=b;b=c;
	}
	int Turn_M (char x[][3])
{
	char a;
	a=x[0][0];x[0][0]=x[2][0];x[2][0]=x[2][2];x[2][2]=x[0][2];x[0][2]=a;
	a=x[0][1];x[0][1]=x[1][0];x[1][0]=x[2][1];x[2][1]=x[1][2];x[1][2]=a;
}

int Turn_m(char x[][3])
{
	Turn_M(x);
	Turn_M(x);
	Turn_M(x);
}

int Turn_Swap(char a[][3],char b[][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++) swap(a[i][j],b[i][j]);
}
			
int Turn_R()
{
	char a[3];
	a[0]=up[0][2];a[1]=up[1][2];a[2]=up[2][2];
	up[0][2]=back[2][0];up[1][2]=back[1][0];up[2][2]=back[0][0];
	back[2][0]=down[0][2];back[1][0]=down[1][2];back[0][0]=down[2][2];
	down[0][2]=front[0][2];down[1][2]=front[1][2];down[2][2]=front[2][2];
	front[0][2]=a[0];front[1][2]=a[1];front[2][2]=a[2];
	Turn_M(right);	
}

int Turn_r ()
{
	Turn_R();
	Turn_R();
	Turn_R();
}

int Turn_L()
{
	char a[3];
	a[0]=up[0][0];a[1]=up[1][0];a[2]=up[2][0];
	up[0][0]=front[0][0];up[1][0]=front[1][0];up[2][0]=front[2][0];
	front[0][0]=down[0][0];front[1][0]=down[1][0];front[2][0]=down[2][0];
	down[0][0]=back[2][2];down[1][0]=back[1][2];down[2][0]=back[0][2];
	back[2][2]=a[0];back[1][2]=a[1];back[0][2]=a[2];
	Turn_M(left);
}	

int Turn_l()
{
	Turn_L();
	Turn_L();
	Turn_L();
}

int Turn_U()
{
	char a[3];
	Turn_M(up);
	a[0]=front[2][0];a[1]=front[2][1];a[2]=front[2][2];
	front[2][0]=left[2][0];front[2][1]=left[2][1];front[2][2]=left[2][2];
	left[2][0]=back[2][0];left[2][1]=back[2][1];left[2][2]=back[2][2];
	back[2][0]=right[2][0];back[2][1]=right[2][1];back[2][2]=right[2][2];
	right[2][0]=a[0];right[2][1]=a[1];right[2][2]=a[2];
}

int Turn_u()
{
	Turn_U();
	Turn_U();
	Turn_U();
}

int Turn_D()
{
	char a[3];
	Turn_M(down);
	a[0]=front[0][0];a[1]=front[0][1];a[2]=front[0][2];
	front[0][0]=right[0][0];front[0][1]=right[0][1];front[0][2]=right[0][2];
	right[0][0]=back[0][0];right[0][1]=back[0][1];right[0][2]=back[0][2];
	back[0][0]=left[0][0];back[0][1]=left[0][1];back[0][2]=left[0][2];
	left[0][0]=a[0];left[0][1]=a[1];left[0][2]=a[2];
}

int Turn_d()
{
	Turn_D();
	Turn_D();
	Turn_D();
}


int Turn_F()
{
	char a[3];
	Turn_M(front);
	a[0]=up[0][0];a[1]=up[0][1];a[2]=up[0][2];
	up[0][0]=right[2][0];up[0][1]=right[1][0];up[0][2]=right[0][0];
	right[2][0]=down[2][2];right[1][0]=down[2][1];right[0][0]=down[2][0];
	down[2][2]=left[0][2];down[2][1]=left[1][2];down[2][0]=left[2][2];
	left[0][2]=a[0];left[1][2]=a[1];left[2][2]=a[2];
}

int Turn_f()
{
	Turn_F();
	Turn_F();
	Turn_F();
}

int Turn_B()
{
	char a[3];
	Turn_M(back);
	a[0]=up[2][0];a[1]=up[2][1];a[2]=up[2][2];
	up[2][0]=left[0][0];up[2][1]=left[1][0];up[2][2]=left[2][0];
	left[0][0]=down[0][2];left[1][0]=down[0][1];left[2][0]=down[0][0];
	down[0][2]=right[2][2];down[0][1]=right[1][2];down[0][0]=right[0][2];
	right[2][2]=a[0];right[1][2]=a[1];right[0][2]=a[2];
}

int Turn_b()
{
	Turn_B();
	Turn_B();
	Turn_B();
}

int Turn_X()
{
	Turn_Swap(front,left);
	Turn_Swap(left,back);
	Turn_Swap(back,right);
	Turn_M(up);
	Turn_m(down);
}	

int Turn_x()
{
	Turn_X();
	Turn_X();
	Turn_X();
}

int Turn_Y()
{
	Turn_F();
	char a[3];
	a[0]=up[1][0];a[1]=up[1][1];a[2]=up[1][2];
	up[1][0]=right[2][1];up[1][1]=right[1][1];up[1][2]=right[0][1];
	right[2][1]=down[1][2];right[1][1]=down[1][1];right[0][1]=down[1][0];
	down[1][2]=left[0][1];down[1][1]=left[1][1];down[1][0]=left[2][1];
	left[0][1]=a[0];left[1][1]=a[1];left[2][1]=a[2];
	Turn_b();
}

int Turn_y()
{
	Turn_Y();
	Turn_Y();
	Turn_Y();
}

int Turn_Z()
{
	Turn_R();
	Turn_l();
	char a[3];
	a[0]=up[0][1];a[1]=up[1][1];a[2]=up[2][1];
	up[0][1]=back[2][1];up[1][1]=back[1][1];up[2][1]=back[0][1];
	back[2][1]=down[0][1];back[1][1]=down[1][1];back[0][1]=down[2][1];
	down[0][1]=front[0][1];down[1][1]=front[1][1];down[2][1]=front[2][1];
	front[0][1]=a[0];front[1][1]=a[1];front[2][1]=a[2];
}

int Turn_z()
{
	Turn_Z();
	Turn_Z();
	Turn_Z();
}		

int Turn_P()
{
	Turn_u();
	Turn_D();
	Turn_X();
}

int Turn_p()
{
	Turn_P();
	Turn_P();
	Turn_P();
}

int Turn_Q()
{
	Turn_f();
	Turn_B();
	Turn_Y();
}

int Turn_q()
{
	Turn_Q();
	Turn_Q();
	Turn_Q();
}

int Turn_W()
{
	Turn_L();
	Turn_r();
	Turn_Z();
}

int Turn_w()
{
	Turn_W();
	Turn_W();
	Turn_W();
}

};
#endif