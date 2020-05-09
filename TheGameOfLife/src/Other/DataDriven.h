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

	void InitBoardStruct();
	void InitPlayerListStruct();

	enum FILETYPES
	{
		BOARD,
		PLAYERLIST
	};

	struct BOARD_DATA_struct
	{
		struct BD_INT_struct
		{
			std::string NAME;
			int MAX;
			int MIN;
			int dd;
		};

		struct BD_FLOAT_struct
		{
			std::string NAME;
			float MAX;
			float MIN;
			float dd;
		};

		std::list<BD_INT_struct*> allBoardData_int;
		std::list<BD_FLOAT_struct*> allBoardData_float;
	};

	struct PLAYERS_DATA_struct
	{
		struct PD_struct
		{
			std::string NAME;
			std::list<CVec2D*> listInitPos;
		};

		std::list<PD_struct*> allPlayersData;
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
	BOARD_DATA_struct mDataBoard;
	PLAYERS_DATA_struct mDataPlayers;
};
