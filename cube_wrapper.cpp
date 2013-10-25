#ifdef __APPLE__
#include <Python/Python.h>
#else
#include <Python.h>
#endif
#include "cube_model.h"
#include "cube_step_one.h"
#include "step_layer2.h"
#include "step_up_face.h"
#include "step_final.h"

#define STATE_FILE "cube.save"

static Cube cubeObj;
typedef char (*face_t)[3];
typedef int (*rotate_func_t)();

face_t faces[6] =
{
	&cubeObj.up[0],
	&cubeObj.down[0],
	&cubeObj.left[0],
	&cubeObj.right[0],
	&cubeObj.front[0],
	&cubeObj.back[0]
};

// rotate_func_t functions[128];
// functions['u'] = cubeObj.Turn_u;

static void setAll(char face[][3], int c)
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j< 3; j++)
			face[i][j] = c;
}
static void do_read_state()
{
	int i;
	FILE * ar = fopen(STATE_FILE,"r");
	if(!ar){
		printf("%s\n", "failed to open " STATE_FILE " for read");
		return;
	}
	for(i=0; i<6; i++)
		fread(faces[i], 1, sizeof(cubeObj.up), ar);
	fclose(ar);
	printf("state read\n");
}
static void do_write_state()
{
	int i;
	FILE * ar = fopen(STATE_FILE,"w");
	if(!ar){
		printf("%s\n", "failed to open " STATE_FILE " for write");
		return;
	}
	for(i=0; i<6; i++)
		fwrite(faces[i], 1, sizeof(cubeObj.up), ar);
	fclose(ar);
	printf("state written\n");
}
static void reset_cube()
{
	int i;
	for(i = 0; i < 6; i++)
		setAll(faces[i], i);
}
PyObject* rotate(PyObject* self, PyObject *args)
{
	char op;
	if(!PyArg_ParseTuple(args, "c", &op))
		return NULL;
	// printf("%d\n", op);

	cubeObj.Apply(op);

	// int i, j, k;
	// for(i=0; i<6; i++)
	// {
	// 	for(j=2; j>=0; j--)
	// 	{
	// 		for(k=0; k<3; k++)
	// 			printf("%d", faces[i][j][k]);
	// 		puts("");
	// 	}
	// 	puts("");
	// }

	Py_INCREF(Py_None);
	return Py_None;
}
PyObject* get(PyObject* self, PyObject *args)
{
	int face, n, m;
	if(!PyArg_ParseTuple(args, "iii", &face, &n, &m))
		return NULL;
	return Py_BuildValue("i", faces[face][n][m]);
}
PyObject* step1(PyObject* self, PyObject *args)
{
	std::string steps = cube_step_one::step_one_solver(cubeObj);
	printf("step1: %s\n", steps.c_str());
	return Py_BuildValue("s", steps.c_str());
}
PyObject* step2(PyObject* self, PyObject *args)
{
	std::string steps = CStep2::run(cubeObj);
	printf("step2: %s\n", steps.c_str());
	return Py_BuildValue("s", steps.c_str());
}
PyObject* step3(PyObject* self, PyObject *args)
{
	std::string steps = CStepUpFace::run(cubeObj);
	printf("step3: %s\n", steps.c_str());
	return Py_BuildValue("s", steps.c_str());
}
PyObject* step4(PyObject* self, PyObject *args)
{
	std::string steps = CStepFinal::run(cubeObj);
	printf("step4: %s\n", steps.c_str());
	return Py_BuildValue("s", steps.c_str());
}
PyObject* readstate(PyObject* self, PyObject *args)
{
	do_read_state();

	Py_INCREF(Py_None);
	return Py_None;
}
PyObject* writestate(PyObject* self, PyObject *args)
{
	do_write_state();
	
	Py_INCREF(Py_None);
	return Py_None;
}
PyObject* reset(PyObject* self, PyObject *args)
{
	reset_cube();
	
	Py_INCREF(Py_None);
	return Py_None;
}
static PyMethodDef cubeMethods[] =
{
	{"reset", reset, METH_VARARGS, "reset to init state"},
	{"rotate", rotate, METH_VARARGS, "rotate face"},
	{"getcolor", get, METH_VARARGS, "get color of a face"},
	{"readstate", readstate, METH_VARARGS, "read state from file"},
	{"writestate", writestate, METH_VARARGS, "write state to file"},
	{"step1", step1, METH_VARARGS, "step1"},
	{"step2", step2, METH_VARARGS, "step2"},
	{"step3", step3, METH_VARARGS, "step3"},
	{"step4", step4, METH_VARARGS, "step4"},
	{NULL, NULL}
};
extern "C"{
void initcube()
{
	reset_cube();

	PyObject* m;
	m = Py_InitModule("cube", cubeMethods);
}
};