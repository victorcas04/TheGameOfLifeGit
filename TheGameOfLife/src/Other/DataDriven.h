#pragma once

#include "defines.h"
#include <list>
#include "Vec2D.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>       // std::isdigit
#include <ctime>		// std::clock()

class CDataDriven
{
public:
	CDataDriven();
	~CDataDriven();

	enum FILETYPES
	{
		BOARD,
		PLAYERLIST
	};

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

	bool ReadBoardFile(std::string filename);
	bool ReadPlayersFile(std::string filename);

	int GetDataRows();
	int GetDataCols();
	int GetDataIter();
	float GetDataTime();
	std::list<CVec2D*> GetDataPlayersNormal();
	std::list<CVec2D*> GetDataPlayersInmortal();

	static std::string AskFileName(FILETYPES filetype = FILETYPES::BOARD);

protected:

private:
	DATABOARD mDataBoard;
	DATAPLAYERS mDataPlayers;
};
