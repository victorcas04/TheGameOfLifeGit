#pragma once

#include "defines.h"
#include <list>
#include "Vec2D.h"

class CDataDriven
{
public:
	CDataDriven();
	~CDataDriven();

	struct DATABOARD
	{
		int ddRows;
		int ddCols;
		int ddIter;
		float ddTime;
	};

	struct DATAPLAYERS
	{
		std::list<CVec2D*> listInitPosNormal;
		std::list<CVec2D*> listInitPosInmortal;
	};

	void ReadBoardFile(const char* filename);
	void ReadPlayersFile(const char* filename);

	int GetDataRows();
	int GetDataCols();
	int GetDataIter();
	float GetDataTime();
	std::list<CVec2D*> GetDataPlayersNormal();
	std::list<CVec2D*> GetDataPlayersInmortal();

protected:

private:
	DATABOARD mDataBoard;
	DATAPLAYERS mDataPlayers;
};
