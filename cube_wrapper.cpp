// #include <Python.h>
#include <Python/Python.h>
#include "Cube_Turn.h"

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
PyObject* rotate(PyObject* self, PyObject *args)
{
	int op;
	int i, j, k;
	if(!PyArg_ParseTuple(args, "c", &op))
		return NULL;
	// printf("%d\n", op);
	switch(op) {
		case 'u':
			cubeObj.Turn_u();
			break;
		case 'U':
			cubeObj.Turn_U();
			break;
		case 'D':
			cubeObj.Turn_D();
			break;
		case 'd':
			cubeObj.Turn_d();
			break;
		case 'l':
			cubeObj.Turn_l();
			break;
		case 'L':
			cubeObj.Turn_L();
			break;
		case 'r':
			cubeObj.Turn_r();
			break;
		case 'R':
			cubeObj.Turn_R();
			break;
		case 'f':
			cubeObj.Turn_f();
			break;
		case 'F':
			cubeObj.Turn_F();
			break;
		case 'b':
			cubeObj.Turn_b();
			break;
		case 'B':
			cubeObj.Turn_B();
			break;
		case 'x':
			cubeObj.Turn_x();
			break;
		case 'X':
			cubeObj.Turn_X();
			break;
		case 'y':
			cubeObj.Turn_y();
			break;
		case 'Y':
			cubeObj.Turn_Y();
			break;
		case 'z':
			cubeObj.Turn_z();
			break;
		case 'Z':
			cubeObj.Turn_Z();
			break;
		case 'p':
			cubeObj.Turn_p();
			break;
		case 'P':
			cubeObj.Turn_P();
			break;
		case 'q':
			cubeObj.Turn_q();
			break;
		case 'Q':
			cubeObj.Turn_Q();
			break;
		case 'w':
			cubeObj.Turn_w();
			break;
		case 'W':
			cubeObj.Turn_W();
			break;
	}
	// printf("Turn_%c\n", op);
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

static PyMethodDef cubeMethods[] =
{
	{"rotate", rotate, METH_VARARGS, "rotate face"},
	{"getcolor", get, METH_VARARGS, "get color of a face"},
	{NULL, NULL}
};
extern "C"{
void initcube()
{
	int i;
	for(i = 0; i < 6; i++)
		setAll(faces[i], i);

	PyObject* m;
	m = Py_InitModule("cube", cubeMethods);
}
};