#pragma once

#include <string>

/// CAN EDIT ///

// RANDOM ////////////////////////////////////////////////////////////////

static std::string RANDOMNAME = "Random";

static bool RANDOMSIZE = true;
static bool RANDOMITER = true;
static bool RANDOMTIME = false;

static int NORMAL_RANDOMPROB = 40;
static int INMORTAL_RANDOMPROB = 1;

// BOARD DATA ///////////////////////////////////////////////////////////////

static std::string BOARDNAME = "Board";
static std::string ROWS_NAME = "rows";
static int ROWS_DEF = 12;
static int ROWS_MAX = 40;
static int ROWS_MIN = 6;

static std::string COLUMNS_NAME = "cols";
static int COLUMNSS_DEF = 28;
static int COLUMNS_MAX = 60;
static int COLUMNS_MIN = 14;

static std::string ITERATIONS_NAME = "iter";
static int ITERATIONS_DEF = 100;
static int ITERATIONS_MAX = 99999;
static int ITERATIONS_MIN = 0;

static std::string TIME_NAME = "time";
static float TIME_DEF = .5f;
static float TIME_MAX = 60.0f;
static float TIME_MIN = .1f;

// PLAYER TYPES ////////////////////////////////////////////////////////////////////////

static std::string PLAYERLISTNAME = "Player list";
static std::string NORMAL_NAME = "normal";
static std::string INMORTAL_NAME = "inmortal";

// GENERAL ///////////////////////////////////////////////////////////////

//#define TEST

// DRAW //////////////////////////////////////////////////////////////////

static bool BUILD = false;
#define DRAW
#define CLEANSCREEN
//#define DRAWDEBUGINFO

///

/// CANNOT EDIT ///

// DATA DRIVEN ///////////////////////////////////////////////////////////

static std::string DATAPATH = (BUILD ? "data/" : "../data/");
static std::string DEFAULTFILENAMEBOARD = "board";
static std::string DEFAULTFILENAMEPLAYERLIST = "players";
static std::string FILEFORMAT = ".txt";

static char SEPARATOR_OPEN = '{';
static char SEPARATOR_CLOSE = '}';
static char DECIMALSEPARATOR = '.';

// DRAW //////////////////////////////////////////////////////////////////

#define DRAWBOARDCHAR '+'
#define DRAWPLAYER_NORMALCHAR 'O'
#define DRAWPLAYER_INMORTALCHAR '@'

///
