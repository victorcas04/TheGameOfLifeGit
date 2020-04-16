
#include "Vec2D.h"

CVec2D::CVec2D(int x, int y)
{
	mX = x;
	mY = y;
}

std::string CVec2D::ToString()
{
	std::string vecString = "";
	vecString.append("(");
	vecString.append(std::to_string(mX));
	vecString.append(", ");
	vecString.append(std::to_string(mY));
	vecString.append(")");
	return vecString;
}

int CVec2D::Pos2DToPos(CVec2D* pos2d, int maxCols)
{
	return pos2d->GetX() * maxCols + pos2d->GetY();
}

CVec2D* CVec2D::PosToPos2D(int pos, int maxCols)
{
	int posX = pos / maxCols;				// rows
	int posY = pos - (maxCols * posX);	// columns
	return new CVec2D(posX, posY);
}
