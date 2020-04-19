
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
	std::string fullpath = std::string(DATAPATH) + filename;
#ifdef DRAWDEBUGINFO
	std::cout << "Board data driven full path: " << fullpath << "\n";
#endif

	std::ifstream myfile(fullpath);
	if (myfile.is_open())
	{
		std::string line;
		std::string r = "rows";
		std::string c = "cols";
		std::string i = "iter";
		std::string t = "time";

		bool bR = false;
		bool bC = false;
		bool bI = false;
		bool bT = false;

		while (getline(myfile, line, ' '))
		{
			if (bR || bC || bI || bT)
			{
				if (bR)
				{
#ifdef DRAWDEBUGINFO
					std::cout << "read rows: " << line << '\n';
#endif			
					mDataBoard.ddRows = std::stoi(line);
					bR = false;
				}
				else if (bC)
				{
#ifdef DRAWDEBUGINFO
					std::cout << "read cols: " << line << '\n';
#endif			
					mDataBoard.ddCols = std::stoi(line);
					bC = false;
				}
				else if (bI)
				{
#ifdef DRAWDEBUGINFO
					std::cout << "read iter: " << line << '\n';
#endif			
					mDataBoard.ddIter = std::stoi(line);
					bI = false;
				}
				else if (bT)
				{
#ifdef DRAWDEBUGINFO
					std::cout << "read time: " << line << '\n';
#endif			
					mDataBoard.ddTime = std::stof(line);
					bT = false;
				}
				myfile.ignore(256, '\n');
			}
			else
			{
				if (line.find(r) != std::string::npos)
				{
					bR = true;
				}
				else if (line.find(c) != std::string::npos)
				{
					bC = true;
				}
				else if (line.find(i) != std::string::npos)
				{
					bI = true;
				}
				else if (line.find(t) != std::string::npos)
				{
					bT = true;
				}
			}
			if (bR || bC || bI || bT)
			{
				myfile.ignore(256, '{');
				while (!std::isdigit(myfile.peek()))
				{
					myfile.ignore(1);
				}
			}
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open " << filename << "\n";
	}
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

	std::ifstream myfile(fullpath);
	if (myfile.is_open())
	{
		std::string line;
		while (getline(myfile, line))
		{
#ifdef DRAWDEBUGINFO
			std::cout << line << '\n';
#endif
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open " << filename << "\n";
	}

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
