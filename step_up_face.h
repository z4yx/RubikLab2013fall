#ifndef STEP_UP_FACE_HPP_
#define STEP_UP_FACE_HPP_

#include "cube_model.h"
#include "formula_tab_up.h"
#include <string>

class CStepUpFace
{
	typedef char (*face_t)[3];
	static bool match(const Cube &cubeObj, const up_face_state_t &s);
	static std::string place_up_face(Cube &cubeObj);
	static std::string try_situation(Cube cubeObj, const up_face_state_t &s);
	static std::string align_corners(Cube &cubeObj);
	static std::string permute_corners(Cube &cubeObj);
public:
	static std::string run(Cube cubeObj);
};

#endif
