
#include "DataDriven.h"

CDataDriven::CDataDriven()
{

}

CDataDriven::~CDataDriven()
{

}

void CDataDriven::InitBoardStruct()
{
	BOARD_DATA_struct::BD_INT_struct* BD_ROWS = new BOARD_DATA_struct::BD_INT_struct();
	BD_ROWS->NAME = ROWS_NAME;
	BD_ROWS->MAX = ROWS_MAX;
	BD_ROWS->MIN = ROWS_MIN;
	mDataBoard.allBoardData_int.push_back(BD_ROWS);

	BOARD_DATA_struct::BD_INT_struct* BD_COLS = new BOARD_DATA_struct::BD_INT_struct();
	BD_COLS->NAME = COLUMNS_NAME;
	BD_COLS->MAX = COLUMNS_MAX;
	BD_COLS->MIN = COLUMNS_MIN;
	mDataBoard.allBoardData_int.push_back(BD_COLS);

	BOARD_DATA_struct::BD_INT_struct* BD_ITER = new BOARD_DATA_struct::BD_INT_struct();
	BD_ITER->NAME = ITERATIONS_NAME;
	BD_ITER->MAX = ITERATIONS_MAX;
	BD_ITER->MIN = ITERATIONS_MIN;
	mDataBoard.allBoardData_int.push_back(BD_ITER);

	BOARD_DATA_struct::BD_FLOAT_struct* BD_TIME = new BOARD_DATA_struct::BD_FLOAT_struct();
	BD_TIME->NAME = TIME_NAME;
	BD_TIME->MAX = TIME_MAX;
	BD_TIME->MIN = TIME_MIN;
	mDataBoard.allBoardData_float.push_back(BD_TIME);
}

void CDataDriven::InitPlayerListStruct()
{
	PLAYERS_DATA_struct::PD_struct* PD_NORMAL = new PLAYERS_DATA_struct::PD_struct();
	PD_NORMAL->NAME = NORMAL_NAME;
	mDataPlayers.allPlayersData.push_back(PD_NORMAL);

	PLAYERS_DATA_struct::PD_struct* PD_INMORTAL = new PLAYERS_DATA_struct::PD_struct();
	PD_INMORTAL->NAME = INMORTAL_NAME;
	mDataPlayers.allPlayersData.push_back(PD_INMORTAL);
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

		// while not eof
		while (getline(myfile, line, ' '))
		{
			for (BOARD_DATA_struct::BD_INT_struct* bdi : mDataBoard.allBoardData_int)
			{
				if (line.find(bdi->NAME) != std::string::npos)
				{
					myfile.ignore(256, '{');

					// keep reading until number
					while (!std::isdigit(myfile.peek()))
					{
						myfile.ignore(1);
					}
					getline(myfile, line, ' ');
#ifdef DRAWDEBUGINFO
					std::cout << "read " << bdi->NAME << " : " << line << '\n';
#endif		
					bdi->dd = std::stoi(line);
					myfile.ignore(256, '\n');
					break;
				}
			}

			for (BOARD_DATA_struct::BD_FLOAT_struct* bdf : mDataBoard.allBoardData_float)
			{
				if (line.find(bdf->NAME) != std::string::npos)
				{
					myfile.ignore(256, '{');
					int p = myfile.peek();

					// keep reading until number or '.'
					while (!std::isdigit(p) && p != '.')
					{
						myfile.ignore(1);
						p = myfile.peek();
					}
					getline(myfile, line, ' ');
#ifdef DRAWDEBUGINFO
					std::cout << "read " << bdf->NAME << " : " << line << '\n';
#endif		
					bdf->dd = std::stof(line);
					myfile.ignore(256, '\n');
					break;
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

		bool bKeepReading = true;
		int x = -1; int y = -1;

		// while not eof
		while (getline(myfile, line, ' '))
		{
			for (PLAYERS_DATA_struct::PD_struct* pd : mDataPlayers.allPlayersData)
			{
				if (line.find(pd->NAME) != std::string::npos)
				{
					myfile.ignore(256, '{');
					bKeepReading = true;

					// while reading a type of player
					while (bKeepReading)
					{
						// while reading a pair ( x , y )
						while (bKeepReading && (x == -1 || y == -1))
						{
							int c = myfile.peek();

							// keep reading until number or '}'
							while (bKeepReading && !std::isdigit(c))
							{
								myfile.ignore(1);
								c = myfile.peek();
								if (c == '}')
								{
									bKeepReading = false;
								}
							}
							if (bKeepReading)
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
						if (bKeepReading)
						{
#ifdef DRAWDEBUGINFO
							std::cout << "read " << pd.NAME << " : ( " << x << " , " << y << " )\n";
#endif				
							pd->listInitPos.push_back(new CVec2D(x, y));
							x = -1; y = -1;
						}
					}
					break;
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
	for (BOARD_DATA_struct::BD_INT_struct* bdi : mDataBoard.allBoardData_int)
	{
		if (bdi->NAME == ROWS_NAME)
		{
			return bdi->dd;
		}
	}
	return 0;
}

int CDataDriven::GetDataCols()
{
	for (BOARD_DATA_struct::BD_INT_struct* bdi : mDataBoard.allBoardData_int)
	{
		if (bdi->NAME == COLUMNS_NAME)
		{
			return bdi->dd;
		}
	}
	return 0;
}

int CDataDriven::GetDataIter()
{
	for (BOARD_DATA_struct::BD_INT_struct* bdi : mDataBoard.allBoardData_int)
	{
		if (bdi->NAME == ITERATIONS_NAME)
		{
			return bdi->dd;
		}
	}
	return 0;
}

float CDataDriven::GetDataTime()
{
	for (BOARD_DATA_struct::BD_FLOAT_struct* bdf : mDataBoard.allBoardData_float)
	{
		if (bdf->NAME == TIME_NAME)
		{
			return bdf->dd;
		}
	}
	return 0.0f;
}

std::list<CVec2D*> CDataDriven::GetDataPlayersNormal()
{
	std::list<CVec2D*> l;
	for (PLAYERS_DATA_struct::PD_struct* pd: mDataPlayers.allPlayersData)
	{
		if (pd->NAME == NORMAL_NAME)
		{
			l = pd->listInitPos;
		}
	}
	return l;
}

std::list<CVec2D*> CDataDriven::GetDataPlayersInmortal()
{
	std::list<CVec2D*> l;
	for (PLAYERS_DATA_struct::PD_struct* pd : mDataPlayers.allPlayersData)
	{
		if (pd->NAME == INMORTAL_NAME)
		{
			l = pd->listInitPos;
		}
	}
	return l;
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
