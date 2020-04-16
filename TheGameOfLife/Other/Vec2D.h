#pragma once

#include <iostream>
#include <string>

class CVec2D
{
public:
	// TODO
	// override functions +, -, *, /

	CVec2D(int x, int y);
	~CVec2D() {}

	int GetX() { return mX; }
	int GetY() { return mY; }

	std::string ToString();

	static int Pos2DToPos(CVec2D* pos2d, int maxCols);
	static CVec2D* PosToPos2D(int pos, int maxCols);

protected:

private:
	int mX;
	int mY;

};
