
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
	int posY = pos - (maxCols * posX);		// columns
	return new CVec2D(posX, posY);
}

CVec2D* operator+(CVec2D& v, CVec2D& v2)
{
	return new CVec2D(v2.GetX() + v.GetX(), v2.GetY() + v.GetY());
}

CVec2D* operator-(CVec2D& v, CVec2D& v2)
{
	return new CVec2D(v.GetX() - v2.GetX(), v.GetY() - v2.GetY());
}

void CVec2D::Test(int maxCols)
{
	CVec2D* test2D = new CVec2D(7, 9);
	int test2Dint = CVec2D::Pos2DToPos(test2D, maxCols);
	std::cout << test2D->ToString() << " -> " << test2Dint << "\n";


	int test = 79;
	CVec2D* testto2D = CVec2D::PosToPos2D(test, maxCols);
	std::cout << test << " -> " << testto2D->ToString() << "\n";

	CVec2D* t1 = new CVec2D(1, 2);
	CVec2D* t2 = new CVec2D(3, 5);
	CVec2D* t3 = *t1 + *t2;
	std::cout << t1->ToString() << " + " << t2->ToString() << " = " << t3->ToString() << "\n";

	CVec2D* t4 = new CVec2D(7, 5);
	CVec2D* t5 = new CVec2D(1, 4);
	CVec2D* t6 = *t4 - *t5;
	std::cout << t4->ToString() << " - " << t5->ToString() << " = " << t6->ToString() << "\n";
}
