
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

bool CDataDriven::ReadBoardFile(std::string filename)
{
	float initTime = static_cast<float>(std::clock());

	std::string fullpath = DATAPATH + filename;
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

		while (getline(myfile, line, ' '))
		{
			if (line.find(strr) != std::string::npos)
			{
				myfile.ignore(256, '{');
				while (!std::isdigit(myfile.peek()))
				{
					myfile.ignore(1);
				}	
				getline(myfile, line, ' ');
#ifdef DRAWDEBUGINFO
				std::cout << "read rows: " << line << '\n';
#endif		
				mDataBoard.ddRows = std::stoi(line);
				myfile.ignore(256, '\n');
			}
			else if (line.find(strc) != std::string::npos)
			{
				myfile.ignore(256, '{');
				while (!std::isdigit(myfile.peek()))
				{
					myfile.ignore(1);
				}	
				getline(myfile, line, ' ');
#ifdef DRAWDEBUGINFO
				std::cout << "read cols: " << line << '\n';
#endif		
				mDataBoard.ddCols = std::stoi(line);
				myfile.ignore(256, '\n');
			}
			else if (line.find(stri) != std::string::npos)
			{
				myfile.ignore(256, '{');
				while (!std::isdigit(myfile.peek()))
				{
					myfile.ignore(1);
				}	
				getline(myfile, line, ' ');
#ifdef DRAWDEBUGINFO
				std::cout << "read cols: " << line << '\n';
#endif		
				mDataBoard.ddIter = std::stoi(line);
				myfile.ignore(256, '\n');
			}
			else if (line.find(strt) != std::string::npos)
			{
				myfile.ignore(256, '{');
				int p = myfile.peek();
				while (!std::isdigit(p) && p != '.')
				{
					myfile.ignore(1);
					p = myfile.peek();
				}		
				getline(myfile, line, ' ');
#ifdef DRAWDEBUGINFO
				std::cout << "read time: " << line << '\n';
#endif	
				mDataBoard.ddTime = std::stof(line);
				myfile.ignore(256, '\n');
			}
		}
		myfile.close();
	}
	else
	{
		std::cout << "ERROR: Unable to open " << filename << "\n";
		return false;
	}
	int elapseTime = static_cast<int>(static_cast<float>(std::clock()) - initTime);
#ifdef DRAWDEBUGINFO
	std::cout << "Read time for " << filename << " : " << std::to_string(elapseTime) << " (ms)\n";
#endif
	return true;
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

bool CDataDriven::ReadPlayersFile(std::string filename)
{
	float initTime = static_cast<float>(std::clock());

	std::string fullpath = DATAPATH + filename;
#ifdef DRAWDEBUGINFO
	std::cout << "Players data driven full path: " << fullpath << "\n";
#endif

	std::ifstream myfile(fullpath);
	if (myfile.is_open())
	{
		std::string line;
		std::string strn = "normal";
		std::string stri = "inmortal";

		bool bKeepReadingNormal = true;
		bool bKeepReadingInmortal = true;

		int x = -1;
		int y = -1;

		while (getline(myfile, line, ' '))
		{
			if (line.find(strn) != std::string::npos)
			{
				myfile.ignore(256, '{');
				while (bKeepReadingNormal)
				{
					while (bKeepReadingNormal && (x == -1 || y == -1))
					{
						int c = myfile.peek();
						while (bKeepReadingNormal && !std::isdigit(c))
						{
							myfile.ignore(1);
							c = myfile.peek();
							if (c == '}')
							{
								bKeepReadingNormal = false;
							}
						}
						if (bKeepReadingNormal)
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
					if (bKeepReadingNormal)
					{
#ifdef DRAWDEBUGINFO
						std::cout << "read normal: ( " << x << " , " << y << " )\n";
#endif				
						mDataPlayers.listInitPosNormal.push_back(new CVec2D(x, y));
						x = -1;
						y = -1;
					}
				}
			}
			else if (line.find(stri) != std::string::npos)
			{
				myfile.ignore(256, '{');
				while (bKeepReadingInmortal)
				{
					while (bKeepReadingInmortal && (x == -1 || y == -1))
					{
						int c = myfile.peek();
						while (bKeepReadingInmortal && !std::isdigit(c))
						{
							myfile.ignore(1);
							c = myfile.peek();
							if (c == '}')
							{
								bKeepReadingInmortal = false;
							}
						}
						if (bKeepReadingInmortal)
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
					if (bKeepReadingInmortal)
					{
#ifdef DRAWDEBUGINFO
						std::cout << "read inmortal: ( " << x << " , " << y << " )\n";
#endif				
						mDataPlayers.listInitPosInmortal.push_back(new CVec2D(x, y));
						x = -1;
						y = -1;
					}
				}
			}
		}
		myfile.close();
	}
	else
	{
		std::cout << "ERROR: Unable to open " << filename << "\n";
		return false;
	}
	int elapseTime = static_cast<int>(static_cast<float>(std::clock()) - initTime);
#ifdef DRAWDEBUGINFO
	std::cout << "Read time for " << filename << " : " << std::to_string(elapseTime) << " (ms)\n";
#endif
	return true;
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

std::string CDataDriven::AskFileName(FILETYPES filetype)
{
	std::string filename;
	std::string whatToLoad;
	std::string filenameDef;
	if (filetype == FILETYPES::BOARD)
	{
		whatToLoad = "Board";
		filenameDef = DEFAULTFILENAMEBOARD;
	}
	else if (filetype == FILETYPES::PLAYERLIST)
	{
		whatToLoad = "Player list";
		filenameDef = DEFAULTFILENAMEPLAYERLIST;
	}
	std::cout << "\nIntroduce filename to load: " << whatToLoad << "\n";
	std::cout << "(Press -R- for random " << whatToLoad << " options)\n";
	std::cout << "(Press -D- for default filename: " << filenameDef << ".txt)\n";
	std::cin >> filename;
	if (filename == "r" || filename == "R")
	{
		return "random";
	}
	if (filename == "d" || filename == "D")
	{
		filename = filenameDef;
	}
	filename += ".txt";
	return filename;
}
