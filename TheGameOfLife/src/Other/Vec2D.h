#pragma once

#include "defines.h"
#include <iostream>
#include <string>

class CVec2D
{
public:
	CVec2D(int x, int y);
	~CVec2D() {}

	int GetX() const { return mX; }
	int GetY() const { return mY; }

	float Dist(const CVec2D* v2) const;
	std::string ToString();

	static int Pos2DToPos(const CVec2D* pos2d, int maxCols);
	static CVec2D* PosToPos2D(int pos, int maxCols);

	static void Test(int maxCols);

protected:

private:
	int mX;
	int mY;

	friend CVec2D* operator+(const CVec2D& v, const CVec2D& v2);
	friend CVec2D* operator-(const CVec2D& v, const CVec2D& v2);
	friend CVec2D* operator*(const CVec2D& v, const CVec2D& v2);
	friend CVec2D* operator/(const CVec2D& v, const CVec2D& v2);

};
