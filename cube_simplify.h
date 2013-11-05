#ifndef CUBE_SIMPLIFY_H_
#define CUBE_SIMPLIFY_H_
#include <string>

class matrix{
public:
	int a[9][9];
	matrix();
	void clear();
	void identity();
	friend matrix operator * (const matrix, const matrix);
};

class cube_simplify{
private:
	static matrix mX, mY, mZ;
	const static int list[9];
	static void cube_simplify_initialize();
	static char change(char, const matrix&);
public:
	static std::string cube_simplify_simplify(std::string);
};

#endif /* CUBE_SIMPLIFY_H_ */
