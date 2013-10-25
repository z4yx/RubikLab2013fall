#include "step_layer2.h"
#include "cube_model.h"
#include <string>
using std::string;

static const char *LAYER2_FORMULA_L = "ULulufUF";
static const char *LAYER2_FORMULA_R = "urURUFuf";
static const char *LAYER2_FORMULA_FLIP = "rUURurUURuXRUr";

string CStep2::corner_place(Cube & cube)
{
	int err = 0;
	string ret;
	while(cube.front[2][0] != cube.front[1][0]){
		ret += 'u';
		cube.Turn_u();
		if(++err > 4){
			fprintf(stderr, "%s: Error: more than 4 moves\n", __func__);
			break;
		}
	}
	return ret;
}
int CStep2::find_incorrect(face_t faces[], bool check_flip)
{
	for(int i=0; i<4; i++) {
		if(faces[i][1][2]!=faces[i][1][1] || faces[i+1][1][1]!=faces[i+1][1][0]){
			if(check_flip && (faces[i][1][2]!=faces[i+1][1][1] || faces[i+1][1][0]!=faces[i][1][1]) )
				continue;
			return i;
		}
	}
	return -1;
}
int CStep2::avai_on_top(const Cube &c)
{
	char top_color = c.up[1][1];
	if(top_color!=c.front[2][1] && top_color!=c.up[0][1])
		return 0;
	if(top_color!=c.right[2][1] && top_color!=c.up[1][2])
		return 1;
	if(top_color!=c.back[2][1] && top_color!=c.up[2][1])
		return 2;
	if(top_color!=c.left[2][1] && top_color!=c.up[1][0])
		return 3;
	return -1;
}
string CStep2::do_place(Cube & cube, face_t faces[])
{
	string ret;
	int avai_pos = avai_on_top(cube);
	// printf("avai_pos = %d\n", avai_pos);
	if(avai_pos==-1){
		fprintf(stderr, "%s: no available on top\n", __func__);
		return ret;
	}
	int side_color = faces[avai_pos][2][1], t = 0;
	while(cube.front[1][1] != side_color){
		cube.Turn_x();
		ret += 'x';
		t++;
	}
	for(int i=(avai_pos - t + 4)%4; i--; ){
		cube.Turn_u();
		ret += 'u';
	}
	if(cube.up[0][1] == cube.right[1][1]){
		cube.ApplyStr(LAYER2_FORMULA_R);
		ret += LAYER2_FORMULA_R;
	}else if(cube.up[0][1] == cube.left[1][1]){
		cube.ApplyStr(LAYER2_FORMULA_L);
		ret += LAYER2_FORMULA_L;
	}else{
		fprintf(stderr, "%s: Error: wrong color\n", __func__);
	}
	return ret;
}
string CStep2::random_place(Cube & cube, face_t faces[])
{
	string ret;
	int incorrect = find_incorrect(faces);
	while(incorrect--){
		ret += 'x';
		cube.Turn_x();
	}
	cube.ApplyStr(LAYER2_FORMULA_R);
	ret += LAYER2_FORMULA_R;
	return ret;
}
//处理棱块位置正确但方向错误的情况
string CStep2::try_correct_flip(Cube & cube, face_t faces[])
{
	string ret;
	int incorrect = find_incorrect(faces, true);
	if(incorrect < 0)
		return ret;
	while(incorrect--){
		ret += 'x';
		cube.Turn_x();
	}
	cube.ApplyStr(LAYER2_FORMULA_FLIP);
	ret += LAYER2_FORMULA_FLIP;
	return ret;
}
string CStep2::run(Cube cubeObj)
{
	string ret;

	face_t faces[] =
	{
		&cubeObj.front[0],
		&cubeObj.right[0],
		&cubeObj.back[0],
		&cubeObj.left[0],
		&cubeObj.front[0]
	};


	while(-1 != find_incorrect(faces)) {
		if(-1 == avai_on_top(cubeObj)){
			// printf("%s\n", "no available on top");
			string tmp = try_correct_flip(cubeObj, faces);
			if(tmp.size()){
				ret += tmp;
				continue;
			}else{
				ret += random_place(cubeObj, faces);
			}
		}
		ret += do_place(cubeObj, faces);
	}

	return ret;
}

