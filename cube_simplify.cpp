#include "cube_simplify.h"
#include <cstring>
//#include <iostream>
#define FFF 0
#define LLL 1
#define BBB 2
#define RRR 3
#define UUU 4
#define DDD 5
#define XXX 6
#define YYY 7
#define ZZZ 8

const int cube_simplify::list[9] = {'F', 'L', 'B', 'R', 'U', 'D', 'X', 'Y', 'Z'};

matrix::matrix(){
	clear();
}
void matrix::clear(){
	memset(a, 0, sizeof(a));
}
void matrix::identity(){
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 9; i++)
		a[i][i] = 1;
}

matrix operator * (const matrix a, const matrix b){
	matrix c;
	c.clear();
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % 4;
	return c;
}

matrix cube_simplify::mX, cube_simplify::mY, cube_simplify::mZ;

void cube_simplify::cube_simplify_initialize(){
	mX.clear(); mY.clear(); mZ.clear();
	mX.a[FFF][LLL] = mX.a[LLL][BBB] = mX.a[BBB][RRR] = mX.a[RRR][FFF] = 1;
	mX.a[UUU][UUU] = mX.a[DDD][DDD] = mX.a[XXX][XXX] = mX.a[ZZZ][YYY] = 1; mX.a[YYY][ZZZ] = 3;

	mY.a[LLL][UUU] = mY.a[UUU][RRR] = mY.a[RRR][DDD] = mY.a[DDD][LLL] = 1;
	mY.a[FFF][FFF] = mY.a[BBB][BBB] = mY.a[YYY][YYY] = mY.a[XXX][ZZZ] = 1; mY.a[ZZZ][XXX] = 3;

	mZ.a[FFF][UUU] = mZ.a[UUU][BBB] = mZ.a[BBB][DDD] = mZ.a[DDD][FFF] = 1;
	mZ.a[LLL][LLL] = mZ.a[RRR][RRR] = mZ.a[ZZZ][ZZZ] = mZ.a[YYY][XXX] = 1; mZ.a[XXX][YYY] = 3;
}

static char uppercase(char ch){
    if ('a' <= ch && ch <= 'z')
        return ch - 'a' + 'A';
    return ch;
}

static char lowercase(char ch){
    if ('A' <= ch && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}

char cube_simplify::change(char ch, const matrix& M){
	int mul = 1;
	if ('a' <= ch && ch <= 'z'){
		mul = 3;
		ch = ch - 'a' + 'A';
	}
	int pp = -1;
	for (int i = 0; i < 9; i++)
		if (list[i] == ch)
			pp = i;
	int qq = -1;
	for (int i = 0; i < 9; i++)
		if (M.a[pp][i]){
			qq = i;
			mul *= M.a[pp][i];
			break;
		}
	if (mul % 4 == 1)
		return list[qq];
	else
		return list[qq] - 'A' + 'a';
}

std::string cube_simplify::cube_simplify_simplify(std::string origen){
	std::string ans;
	cube_simplify_initialize();
	int n = origen.size();
	matrix M;
	M.identity();
	for (int i = 0; i < n; i++){
		char ch = change(origen[i], M);

		if (ch == 'X')
			M = M * mX;
		else if (ch == 'x')
			M = M * mX * mX * mX;
		else if (ch == 'Y')
			M = M * mY;
		else if (ch == 'y')
			M = M * mY * mY * mY;
		else if (ch == 'Z')
			M = M * mZ;
		else if (ch == 'z')
		 	M = M * mZ * mZ * mZ;
		else
			ans += ch;
	}
    std::string sol = "";
    for (int i = 0; i < (int)ans.size(); i++){
        int j, cnt = 0;
        for (j = i; j < (int)ans.size(); j++)
            if (uppercase(ans[i]) == uppercase(ans[j]))
                cnt += 1 + (uppercase(ans[j]) == ans[j]) * 2;
            else
                break;
        cnt %= 4;
        if (cnt == 1)
            sol += lowercase(ans[i]);
        else if (cnt == 2){
            sol += lowercase(ans[i]);
            sol += lowercase(ans[i]);
        }
        else if (cnt == 3){
            sol += uppercase(ans[i]);
        }
        i = j - 1;
    }
	return sol;
}
/*
int main(){
	std::string ss;
	std::cin >> ss;
	std::cout << cube_simplify::cube_simplify_simplify(ss) << std::endl;
}
*/