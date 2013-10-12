#ifndef solve_2_H
#define solve_2_H
#include <string.h>
#include <stdio.h>
#include <string>
#include "Cube_Turn.h"
#include <cstring>
#include <iostream>

using namespace std;

struct second
{
string ans;
public:
bool solve2_check(char a[3][3],int j)
{
  for (int i=0;i<=1;i++)
    if (a[j][i]!=a[j][i+1]) return false;
  return true;
}

bool solve2_check1(Cube a)
{
  for (int i=0;i<2;i++)
  {
    if (a.front[0][i]!=a.front[0][i+1]) return false;
    if (a.left[0][i]!=a.left[0][i+1]) return false;
    if (a.right[0][i]!=a.right[0][i+1]) return false;
    if (a.back[0][i]!=a.back[0][i+1]) return false;            
    for (int j=0;j<2;j++)
      if (a.down[i][j]!=a.down[i+1][j] || a.down[i][j]!=a.down[i][j+1]) return false;
  }
  return true;
}

void add(char t)
{
  ans=ans+t;
}

bool solve2_check2(Cube a)
{
  for (int i=0;i<=1;i++)
    for (int j=0;j<=1;j++)
      if (a.down[i][j]!=a.down[i+1][j] || a.down[i][j]!=a.down[i][j+1]) return false;
  return (solve2_check(a.front,0) && solve2_check(a.front,1) && solve2_check(a.back,0) && solve2_check(a.back,1))&&
         (solve2_check(a.right,0) && solve2_check(a.right,1) && solve2_check(a.left,0) && solve2_check(a.left,1));
}

void solve2_r(Cube &a)
{
  a.Turn_u();add('u');a.Turn_r();add('r');
  a.Turn_U();add('U');a.Turn_R();add('R');
  a.Turn_U();add('U');a.Turn_F();add('F');
  a.Turn_u();add('u');a.Turn_f();add('f');
}

void solve2_l(Cube &a)
{
  a.Turn_U();add('U');a.Turn_F();add('F');
  a.Turn_u();add('u');a.Turn_f();add('f');
  a.Turn_u();add('u');a.Turn_r();add('r');
  a.Turn_U();add('U');a.Turn_R();add('R');
}

void solve2_work(Cube &a,char c1,char c2)
{
  for (int i=1;i<=4;i++)
  {
    if (a.front[2][1]==c1 && a.up[0][1]==c2) return;
    if (a.front[2][1]==c2 && a.up[0][1]==c1) return;
    a.Turn_u();add('u');
  }
  for (int i=1;i<=4;i++)
  {
    if (a.front[1][2]==c1 && a.right[1][0]==c2) break;
    if (a.front[1][2]==c2 && a.right[1][0]==c1) break;    
    a.Turn_x();add('x');
  }
  for (int i=1;i<=4;i++)
  {
    if (a.front[2][1]==a.up[1][1] || a.up[0][1]==a.up[1][1]) break;
    a.Turn_u();add('u');
  }
  solve2_r(a);
  for (int i=1;i<=4;i++)
    if (a.front[0][0]==c1) break; else {a.Turn_x();add('x');}
  for (int i=1;i<=4;i++)
  {
    if (a.front[2][1]==c1 && a.up[0][1]==c2) return;
    if (a.front[2][1]==c2 && a.up[0][1]==c1) return;    
    a.Turn_u();add('u');
  }
}

void solve_2_before(Cube &a)
{
  int i;
  for (i=1;i<=4;i++)
    if (solve2_check1(a)) return; else {a.Turn_Z();add('Z');}
  a.Turn_Y();add('Y');
  for (i=1;i<=2;i++)
    if (solve2_check1(a)) return; else {a.Turn_Y();add('Y');a.Turn_Y();add('Y');}

}

string solve_2(Cube a)
{
  int i;
  solve_2_before(a);
  for (i=1;i<=4;i++)
    if (a.front[0][1]==a.front[1][1]) break; else {a.Turn_p();add('p');}
    
  while (!solve2_check2(a))
  {
    for (i=1;i<=4;i++)
    {
      if (a.front[1][2]!=a.front[0][0] || a.right[1][0]!=a.right[0][0])
      {
        solve2_work(a,a.front[0][0],a.right[0][0]);
        if (a.front[2][1]==a.front[0][0]) solve2_r(a);
      }
      a.Turn_X();add('X');
    }
    for (i=1;i<=4;i++)
    {
      if (a.left[1][2]!=a.left[0][0] || a.front[1][0]!=a.front[0][0])
      {
        solve2_work(a,a.left[0][0],a.front[0][0]);
        if (a.front[2][1]==a.front[0][0]) solve2_l(a);        
      }
      a.Turn_X();add('X');
    }
  }
  return ans;
}
};
#endif

/*
Cube a;

int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  for (int i=2;i>=0;i--)
    for (int j=0;j<3;j++)
      cin>>a.front[i][j];
  for (int i=2;i>=0;i--)
    for (int j=0;j<3;j++)
      cin>>a.right[i][j];
  for (int i=2;i>=0;i--)
    for (int j=0;j<3;j++)
      cin>>a.back[i][j];
  for (int i=2;i>=0;i--)
    for (int j=0;j<3;j++)
      cin>>a.left[i][j];
  for (int i=2;i>=0;i--)
    for (int j=0;j<3;j++)
      cin>>a.up[i][j];
  for (int i=2;i>=0;i--)
    for (int j=0;j<3;j++)
      cin>>a.down[i][j];
  cout<<solve_2(a)<<endl;
  return 0;
}
*/ 
