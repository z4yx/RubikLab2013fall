#ifndef second_H
#define second_H
#include<stdio.h>
#include<string.h>
#include"Cube_Turn.h"
using namespace std;
struct Second
{
       string s,s1,s2;
public:
void Turn1(Cube &x)
{
     x.Turn_u();x.Turn_r();x.Turn_U();x.Turn_R();
     x.Turn_U();x.Turn_F();x.Turn_u();x.Turn_f();
}
void Turn2(Cube &x)
{
     x.Turn_U();x.Turn_L();x.Turn_u();x.Turn_l();
     x.Turn_u();x.Turn_f();x.Turn_U();x.Turn_F();
}
bool Pd_Ture(Cube &x)
{
	if(x.front[1][0]==x.front[1][1] && x.front[1][2]==x.front[1][1])
		if(x.left[1][0]==x.left[1][1] && x.left[1][2]==x.left[1][1])
			if(x.right[1][0]==x.right[1][1] && x.right[1][2]==x.right[1][1])
				if(x.back[1][0]==x.back[1][1] && x.back[1][2]==x.back[1][1]) return 1;
	return 0;
}
bool Pd_Main(Cube &x)
{
	string ss="";
	for(int i=1;i<=4;i++)
	{
		if(x.front[2][1]!=x.up[1][1] && x.up[0][1]!=x.up[1][1])	break;
		x.Turn_U();ss+="U";
	}
	if(x.front[2][1]==x.up[1][1] || x.up[0][1]==x.up[1][1]) return 0;
	s+=ss;
	for(int i=1;i<=4;i++)
	{
		if(x.front[2][1]==x.front[1][1]) break;
		x.Turn_u();x.Turn_X();s+="uX";
	}
	if(x.up[0][1]==x.left[1][1])
	{
		Turn2(x);s+=s2;
		return 1;
	}
	if(x.up[0][1]==x.right[1][1])
	{
		Turn1(x);s+=s1;
		return 1;
	}
}
int Pd_Xiao(Cube &x)
{
	string ss="";
	for(int i=1;i<=4;i++)
	{
		if(x.front[1][2]==x.up[1][1] || x.right[1][0]==x.up[1][1]) break;
		x.Turn_X();ss+="X";
	}
	if(x.front[1][2]==x.up[1][1] || x.right[1][0]==x.up[1][1]) s+=ss;
	Turn1(x);s+=s1;
}
int Get(char x[][3])
{
	int i,j;
	char c;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin >> x[i][j];
}
int Pri(char x[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout << x[i][j];
		cout << endl;
	}
	cout << endl;
}
string Main(Cube x)
{
    s="";s1="urURUFuf";s2="ULulufUF";
	for(int i=1;i<=4;i++) 
 	{
             if(x.front[1][1]==x.front[0][1]) break;
             s+="D";x.Turn_D();
	}
	for(;;)
	{
		for(;Pd_Main(x););
		if(Pd_Ture(x)) break;
		Pd_Xiao(x);
	}
    return s;
}
};
#endif
