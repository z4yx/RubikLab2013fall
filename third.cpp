#include<iostream>
#include<cstdio>
#include"Cube_Turn.h"
#include"Third.h"
using namespace std;
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
Cube cube;
int main()
{
	freopen("cube.txt","r",stdin);
	Get(cube.front);
	Get(cube.back);
	Get(cube.left);
	Get(cube.right);
	Get(cube.up);
	Get(cube.down);
	Third ab;
	ab.Main(cube);
	Pri(cube.front);
	Pri(cube.back);
	Pri(cube.left);
	Pri(cube.right);
	Pri(cube.up);
	Pri(cube.down);
	cout << ab.s << endl;
	return 0;
}
