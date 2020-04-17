#pragma once

#include <iostream>
#include <string>

class CVec2D
{
public:
	CVec2D(int x, int y);
	~CVec2D() {}

	int GetX() const { return mX; }
	int GetY() const { return mY; }

	std::string ToString();

	static int Pos2DToPos(CVec2D* pos2d, int maxCols);
	static CVec2D* PosToPos2D(int pos, int maxCols);

	static void Test(int maxCols);

protected:

private:
	int mX;
	int mY;

	friend CVec2D* operator+(CVec2D& v, CVec2D& v2);
	friend CVec2D* operator-(CVec2D& v, CVec2D& v2);

};
