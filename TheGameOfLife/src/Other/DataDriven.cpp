
#include "DataDriven.h"

CDataDriven::CDataDriven()
{

}

CDataDriven::~CDataDriven()
{

}

// BOARD FORMAT
/*
	rows { 24 }
	cols { 12 }
	iter { 10 }
	time { 10.0 }
*/

void CDataDriven::ReadBoardFile(const char* filename)
{
	float initTime = static_cast<float>(std::clock());

	std::string fullpath = std::string(DATAPATH) + filename;
#ifdef DRAWDEBUGINFO
	std::cout << "Board data driven full path: " << fullpath << "\n";
#endif

	std::ifstream myfile(fullpath);
	if (myfile.is_open())
	{
		std::string line;
		std::string strr = "rows";
		std::string strc = "cols";
		std::string stri = "iter";
		std::string strt = "time";

		bool bR = false;
		bool bC = false;
		bool bI = false;
		bool bT = false;

		// TODO: refactor

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
				if (line.find(strr) != std::string::npos)
				{
					bR = true;
				}
				else if (line.find(strc) != std::string::npos)
				{
					bC = true;
				}
				else if (line.find(stri) != std::string::npos)
				{
					bI = true;
				}
				else if (line.find(strt) != std::string::npos)
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
	int elapseTime = static_cast<int>(static_cast<float>(std::clock()) - initTime);
#ifdef DRAWDEBUGINFO
	std::cout << "Read time for " << filename << " : " << std::to_string(elapseTime) << " (ms)\n";
#endif
}

// PLAYERS FORMAT
/*
	normal {
		( 0 , 1 ),
		( 1 , 0 ),
		( 1 , 1 ),
		( 1 , 2 )
	}

	inmortal {
		( 3 , 0 ),
		( 3 , 3 )
	}
*/

void CDataDriven::ReadPlayersFile(const char* filename)
{
	float initTime = static_cast<float>(std::clock());

	std::string fullpath = std::string(DATAPATH) + filename;
#ifdef DRAWDEBUGINFO
	std::cout << "Players data driven full path: " << fullpath << "\n";
#endif

	std::ifstream myfile(fullpath);
	if (myfile.is_open())
	{
		std::string line;
		std::string strn = "normal";
		std::string stri = "inmortal";

		bool bN = false;
		bool bI = false;

		int x = -1;
		int y = -1;
		bool canN = false;
		bool canI = false;

		// TODO: refactor

		while (getline(myfile, line, ' '))
		{
			if (bN || bI)
			{
				while (bN)
				{
					while (bN && (x == -1 || y == -1))
					{
						int c = myfile.peek();
						while (bN && !std::isdigit(c))
						{
							myfile.ignore(1);
							c = myfile.peek();
							if (c == '}')
							{
								bN = false;
							}
						}
						if (bN)
						{
							getline(myfile, line, ' ');
							if (x == -1)
							{
								x = std::stoi(line);
							}
							else if (y == -1)
							{
								y = std::stoi(line);
							}
						}
					}
					if (bN)
					{
#ifdef DRAWDEBUGINFO
						std::cout << "read normal: ( " << x << " , " << y << " )\n";
#endif				
						mDataPlayers.listInitPosNormal.push_back(new CVec2D(x, y));
						x = -1;
						y = -1;
					}
				}
				while (bI)
				{
					while (bI && (x == -1 || y == -1))
					{
						int c = myfile.peek();
						while (bI && !std::isdigit(c))
						{
							myfile.ignore(1);
							c = myfile.peek();
							if (c == '}')
							{
								bI = false;
							}
						}
						if (bI)
						{
							getline(myfile, line, ' ');
							if (x == -1)
							{
								x = std::stoi(line);
							}
							else if (y == -1)
							{
								y = std::stoi(line);
							}
						}
					}
					if (bI)
					{
#ifdef DRAWDEBUGINFO
						std::cout << "read inmortal: ( " << x << " , " << y << " )\n";
#endif				
						mDataPlayers.listInitPosInmortal.push_back(new CVec2D(x, y));
						x = -1;
						y = -1;
					}
				}
				myfile.ignore(256, '\n');
			}
			else
			{
				if (line.find(strn) != std::string::npos)
				{
					bN = true;
				}
				else if (line.find(stri) != std::string::npos)
				{
					bI = true;
				}
				myfile.ignore(256, '{');
			}
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open " << filename << "\n";
	}
	int elapseTime = static_cast<int>(static_cast<float>(std::clock()) - initTime);
#ifdef DRAWDEBUGINFO
	std::cout << "Read time for " << filename << " : " << std::to_string(elapseTime) << " (ms)\n";
#endif
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
