#ifndef Third_sec
#define Third_sec
#include<string.h>
#include"Cube_Turn.h"
using namesapce std;

struct Third_sec
{
	string s,s1,s2;
public:
	void Turn(Cube &x)
	{
		x.Turn_Z();
		x.Turn_r();x.Turn_r();x.Turn_d();x.Turn_d();x.Turn_R();
		x.Turn_U();x.Turn_r();x.Turn_d();x.Turn_d();x.Turn_R();
		x.Turn_u();x.Turn_R();
		x.Turn_z();
	}
	string Main(Cube x)
	{
		s="";s1="";
		s2="ZrrddRUrddRuRz";
		if(x.right[2][0]==x.right[2][2] && x.front[2][2]==x.front[2][0]) return "";
		for(i=1;i<=4;i++)
		{	
			if(x.right[2][0]==x.right[2][2]) break;
			x.Turn_X();s1+="X";
		}
		if(x.right[2][0]!=x.right[2][2]){Turn(x);s+=s2;}
		else s=s1;
		for(i=1;i<=4;i++)
		{	
			if(x.right[2][0]==x.right[2][2]) break;
			x.Turn_X();s+="X";
		}
		if(x.right[2][0]==x.right[2][2] && x.front[2][2]==x.front[2][0]) return "";
		Turn(x);s+=s2;
		return s;
	}
};
#endif
