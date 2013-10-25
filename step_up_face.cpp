#include "step_up_face.h"
#include "cube_model.h"
#include <cstdio>
#include <string>
using std::string;

bool CStepUpFace::match(const Cube &cubeObj, const up_face_state_t &s)
{
	char up_color = cubeObj.up[1][1];

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(s.up_img[3-i][j+1] && (cubeObj.up[i][j] != up_color) )
				return false;
	for(int i=0; i<3; i++)
		if(s.up_img[4][i+1] && (cubeObj.front[2][i] != up_color) )
			return false;
	for(int i=0; i<3; i++)
		if(s.up_img[0][3-i] && (cubeObj.back[2][i] != up_color) )
			return false;
	for(int i=0; i<3; i++)
		if(s.up_img[3-i][4] && (cubeObj.right[2][i] != up_color) )
			return false;
	for(int i=0; i<3; i++)
		if(s.up_img[1+i][0] && (cubeObj.left[2][i] != up_color) )
			return false;
	return true;
}
string CStepUpFace::try_situation(Cube cubeObj, const up_face_state_t &s)
{
	for(int i=0; i<4; i++) {
		if(match(cubeObj, s)){
			if(i == 3)
				return string("U") + s.apply_formula;
			else if(i == 2)
				return string("uu") + s.apply_formula;
			else if(i == 1)
				return string("u") + s.apply_formula;
			else
				return s.apply_formula;
		}
		cubeObj.Turn_u();
	}
	return "";
}

string CStepUpFace::place_up_face(Cube &cubeObj)
{
	string steps;

	while(!match(cubeObj, up_face_finished)) {
		int len = sizeof(up_face_states)/sizeof(up_face_state_t);
		for(int i=0; i<len; i++) {
			string ret = try_situation(cubeObj, up_face_states[i]);
			if(ret.size()) {
				steps += ret;
				cubeObj.ApplyStr(ret.c_str());
				fprintf(stderr, "%s%d\n", "solution found: ", i);
				break;
			}
		}
	}

	return steps;
}
string CStepUpFace::permute_corners(Cube &cubeObj)
{
	const char * formula_6 = "rBrffRbrffrr";
	string ret;
	for(;;) {
		int num = 0;
		Cube tmpCube = cubeObj;
		for(int i=0; i<4; i++) {
			if(tmpCube.front[2][0] != tmpCube.front[2][2])
				num++;
			tmpCube.Turn_u();
		}
		if(!num)
			break;
		printf("num: %d\n", num);

		if(num < 4) {
			for(int i=0; i<4; i++) {
				if(cubeObj.front[2][0] == cubeObj.front[2][2]){
					break;
				}
				ret += 'u';
				cubeObj.Turn_u();
			}
		}
		ret += formula_6;
		cubeObj.ApplyStr(formula_6);
	}
	return ret;
}
string CStepUpFace::align_corners(Cube &cubeObj)
{
	string ret;
	while(cubeObj.front[1][0] != cubeObj.front[2][0]) {
		ret += 'u';
		cubeObj.Turn_u();
	}
	return ret;
}
string CStepUpFace::run(Cube cubeObj)
{
	string ret;

	ret += place_up_face(cubeObj);
	ret += permute_corners(cubeObj);
	ret += align_corners(cubeObj);

	return ret;
}

