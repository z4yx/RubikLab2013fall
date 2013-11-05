#ifndef STEP_FINAL_HPP_
#define STEP_FINAL_HPP_

#include "cube_model.h"
#include <string>

class CStepFinal
{
	typedef char (*face_t)[3];

	static std::string corner_place(Cube & cube);
	static std::string dirty_scan(Cube & cube, face_t faces[4]);
public:
	static std::string run(Cube cubeObj);
};

#endif