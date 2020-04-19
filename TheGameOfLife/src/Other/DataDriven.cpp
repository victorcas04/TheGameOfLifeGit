
#include "DataDriven.h"

CDataDriven::CDataDriven()
{

}

CDataDriven::~CDataDriven()
{

}

void CDataDriven::ReadBoardFile(const char* filename)
{
	// BOARD FORMAT
/*
rows { 24 }
cols { 12 }
iter { 10 }
time { 10.0 }
*/
	// TODO
	std::string fullpath = std::string(DATAPATH) + filename;
#ifdef DRAWDEBUGINFO
	std::cout << "Board data driven full path: " << fullpath << "\n";
#endif

	mDataBoard.ddRows = 16;
	mDataBoard.ddCols = 14;
	mDataBoard.ddIter = 10;
	mDataBoard.ddTime = 10.0;
}

void CDataDriven::ReadPlayersFile(const char* filename)
{
	// PLAYERS FORMAT
/*
normal {
	(0, 1),
	(1, 0),
	(1, 1),
	(1, 2)
}

inmortal {
	(3, 0),
	(3, 3)
}
*/
	// TODO
	std::string fullpath = std::string(DATAPATH) + filename;
#ifdef DRAWDEBUGINFO
	std::cout << "Players data driven full path: " << fullpath << "\n";
#endif

	mDataPlayers.listInitPosNormal.push_back(new CVec2D(0, 1));
	mDataPlayers.listInitPosNormal.push_back(new CVec2D(1, 0));
	mDataPlayers.listInitPosNormal.push_back(new CVec2D(1, 1));
	mDataPlayers.listInitPosNormal.push_back(new CVec2D(1, 2));

	mDataPlayers.listInitPosInmortal.push_back(new CVec2D(3, 0));
	mDataPlayers.listInitPosInmortal.push_back(new CVec2D(3, 3));
}

int CDataDriven::GetDataRows()
{
	return mDataBoard.ddRows;
}

int CDataDriven::GetDataCols()
{
	return mDataBoard.ddCols;
}

int CDataDriven::GetDataIter()
{
	return mDataBoard.ddIter;
}

float CDataDriven::GetDataTime()
{
	return mDataBoard.ddTime;
}

std::list<CVec2D*> CDataDriven::GetDataPlayersNormal()
{
	return mDataPlayers.listInitPosNormal;
}

std::list<CVec2D*> CDataDriven::GetDataPlayersInmortal()
{
	return mDataPlayers.listInitPosInmortal;
}
