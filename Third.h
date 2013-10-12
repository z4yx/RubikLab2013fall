#ifndef Third_H
#define Third_H
#include<stdio.h>
#include<string.h>
#include"Cube_Turn.h"
using namespace std;
struct Third
{
	string s,turn1,turn2;
	bool Pd1(Cube &x)
	{
		char a=x.up[1][1];
		if(x.up[0][0]==a && x.up[0][1]==a && x.up[1][0]==a && x.up[1][2]==a && x.up[2][1]==a && x.right[2][0]==a && x.left[2][0]==a && x.back[2][0]==a) return 1;
		else return 0;
	}
	bool Pd2(Cube &x)
	{
		char a=x.up[1][1];
		if(x.up[0][0]==a && x.up[0][1]==a && x.up[1][0]==a && x.up[1][2]==a && x.up[2][1]==a && x.front[2][2]==a && x.right[2][2]==a && x.back[2][2]==a) return 1;
		else return 0;
	}
	void Turn1(Cube &x)
	{
		x.Turn_R();x.Turn_U();x.Turn_r();x.Turn_U();x.Turn_R();x.Turn_U();x.Turn_U();x.Turn_r();
	}
	void Turn2(Cube &x)
	{
		x.Turn_l();x.Turn_u();x.Turn_L();x.Turn_u();x.Turn_l();x.Turn_u();x.Turn_u();x.Turn_L();
	}
	bool Pd_Main(Cube &x)
	{
		char a=x.up[1][1];
		string ss="";
		for(int i=1;i<=4;i++)
		{
			x.Turn_U();
			ss+="U";
			if(Pd1(x) || Pd2(x)) break;
		}
		if(Pd1(x))
		{
			x.Turn_U();x.Turn_U();x.Turn_U();ss+="UUU";
			Turn1(x);ss+=turn1;s+=ss;
			return 1;
		}
		if(Pd2(x))
		{
			x.Turn_U();x.Turn_U();ss+="UU";
			Turn2(x);ss+=turn2;s+=ss;
			return 1;
		}
		return 0;
	}
	bool Pd_Xiao(Cube &x)
	{
		char a=x.up[1][1];
		string ss="";
		for(int i=1;i<=4;i++)
		{
			x.Turn_U();ss+="U";
			if(x.up[1][0]==a && x.up[2][1]==a)
			{
				x.Turn_R();x.Turn_U();x.Turn_F();
				x.Turn_u();x.Turn_f();x.Turn_r();
				ss+="RUFufr";s+=ss;
				return 1;
			}
		}
		x.Turn_R();x.Turn_U();x.Turn_F();
		x.Turn_u();x.Turn_f();x.Turn_r();
		s+="RUFufr";
		return 0;
	}
	bool Pd_Mid(Cube &x)
	{
		string ss;
		ss="";
		for(int i=1;i<=4;i++)
		{
			x.Turn_U();
			ss="U";ss+=turn1;
			Turn1(x);if(Pd_Main(x)){s+=ss;return 1;}
			Turn2(x);
		}
		return 0;
	}
				
	void Main(Cube &x)
	{
		s="";turn1="RUrURUUr";
		turn2="luLuluuL";
		if(Pd_Main(x)) return;
		if(Pd_Mid(x)) return;
		for(;!Pd_Xiao(x););
		if(Pd_Mid(x)) return;
	}
};
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

