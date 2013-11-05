#ifndef FORMULA_TAB_UP_H_
#define FORMULA_TAB_UP_H_

struct up_face_state_t
{
	//顶层展开状态,1表示与顶层颜色相同
	char up_img[5][5];

	//状态对应的公式
	const char *apply_formula;
};

static const char *FORMULA_4_1 = "fruRUF";
static const char *FORMULA_4_2 = "furURF";
static const char *FORMULA_5_1 = "RuuruRur";
static const char *FORMULA_5_2 = "UruuRUrUR";

static const char *FORMULA_OLL_3 = "ruRurURuruuR";
static const char *FORMULA_OLL_4 = "rUURRUrrURRUUr";
static const char *FORMULA_OLL_5 = "zluRUZLfrF";
static const char *FORMULA_OLL_6 = "ruRurUURurUURUrUR";
static const char *FORMULA_OLL_7 = "FzluRUZLfr";

static const up_face_state_t up_face_finished =
{

	{
		{0, 0, 0, 0, 0},
		{0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 0, 0}
	},
	0
};

static const up_face_state_t up_face_states[] = 
{
	//一步可使顶层面位
	{
		{
			{0, 1, 0, 0, 0},
			{0, 0, 1, 0, 1},
			{0, 1, 1, 1, 0},
			{1, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
		FORMULA_5_1
	},
	{
		{
			{0, 0, 0, 1, 0},
			{1, 0, 1, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0}
		},
		FORMULA_5_2
	},
	{
		{
			{0, 0, 0, 0, 0},
			{1, 0, 1, 0, 1},
			{0, 1, 1, 1, 0},
			{1, 0, 1, 0, 1},
			{0, 0, 0, 0, 0}
		},
		FORMULA_OLL_3
	},
	{
		{
			{0, 0, 0, 0, 0},
			{1, 0, 1, 1, 0},
			{0, 1, 1, 1, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 1, 0}
		},
		FORMULA_OLL_7
	},
	{
		{
			{0, 0, 0, 1, 0},
			{1, 0, 1, 0, 0},
			{0, 1, 1, 1, 0},
			{1, 0, 1, 0, 0},
			{0, 0, 0, 1, 0}
		},
		FORMULA_OLL_4
	},
	{
		{
			{0, 1, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0}
		},
		FORMULA_OLL_5
	},
	{
		{
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 0, 1, 0}
		},
		FORMULA_OLL_6
	},
	//得到顶层十字
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0}
		},
		FORMULA_4_1
	},
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 1, 0, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0}
		},
		FORMULA_4_2
	},
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0}
		},
		FORMULA_4_2
	},
};

#endif
