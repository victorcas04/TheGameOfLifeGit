#pragma once

#include <string>


/// CAN EDIT ///

// BOARD DATA ///////////////////////////////////////////////////////////////

static std::string ROWS_NAME = "rows";
static int ROWS_MAX = 40;
static int ROWS_MIN = 6;

static std::string COLUMNS_NAME = "cols";
static int COLUMNS_MAX = 60;
static int COLUMNS_MIN = 14;

static std::string ITERATIONS_NAME = "iter";
static int ITERATIONS_MAX = 99999;
static int ITERATIONS_MIN = 0;

static std::string TIME_NAME = "time";
static float TIME_MAX = 60.0f;
static float TIME_MIN = .1f;

// PLAYER TYPES ////////////////////////////////////////////////////////////////////////

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

// DRAW //////////////////////////////////////////////////////////////////

#define DRAWBOARDCHAR '+'
#define DRAWPLAYER_NORMALCHAR 'O'
#define DRAWPLAYER_INMORTALCHAR '@'

///
