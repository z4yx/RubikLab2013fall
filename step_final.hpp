#include "cube_model.h"
#include <string>
using std::string;

const char *FINAL_STEP_FORMULA = "rUrururURUrr";
class CStepFinal
{
	typedef char (*face_t)[3];

	static string corner_place(Cube & cube)
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
	static void apply(Cube & cubeObj, const char *s)
	{
		for(int i=0; s[i]; i++)
			cubeObj.Apply(s[i]);
	}
	static string dirty_scan(Cube & cube, face_t faces[4])
	{
		string ret;
		bool dirty[4] = {0};
		int dirty_cnt = 0;

		for(int i=0; i<4; i++){
			if(faces[i][1][1] != faces[i][2][1]){
				dirty_cnt++;
				dirty[i] = true;
			}
		}
		if(!dirty_cnt)
			return ret;

		if(dirty_cnt == 4){
			ret += FINAL_STEP_FORMULA;
			apply(cube, FINAL_STEP_FORMULA);
			ret += dirty_scan(cube, faces);
		}else if(dirty_cnt == 3){
			while(faces[2][1][1] != faces[2][2][1]){ //背面棱块不同
				ret += 'x';
				cube.Turn_x();
			}
			ret += FINAL_STEP_FORMULA;
			apply(cube, FINAL_STEP_FORMULA);
			ret += dirty_scan(cube, faces);
		}else{
			fprintf(stderr, "dirty_cnt cannot be %d\n", dirty_cnt);
		}
		return ret;
	}
public:
	static string run(Cube cubeObj)
	{
		string ret;

		face_t faces[4] =
		{
			&cubeObj.front[0],
			&cubeObj.right[0],
			&cubeObj.back[0],
			&cubeObj.left[0]
		};

		ret += corner_place(cubeObj);
		ret += dirty_scan(cubeObj, faces);

		return ret;
	}

};