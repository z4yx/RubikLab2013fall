#ifndef STEP_LAYER2_HPP_
#define STEP_LAYER2_HPP_

#include "cube_model.h"
#include <string>

class CStep2
{
	typedef char (*face_t)[3];

	static std::string corner_place(Cube & cube);
	static int find_incorrect(face_t faces[], bool check_flip = false);
	static int avai_on_top(const Cube &c);
	static std::string do_place(Cube & cube, face_t faces[]);
	static std::string random_place(Cube & cube, face_t faces[]);
	static std::string try_correct_flip(Cube & cube, face_t faces[]);
public:
	static std::string run(Cube cubeObj);

};

#endif
