#pragma once

#include <string>


/// CAN EDIT ///

// BOARD DATA ///////////////////////////////////////////////////////////////

#define MAXROWS 40
#define MINROWS 6

#define MAXCOLS 60
#define MINCOLS 14

#define MAXITER 99999
#define MINITER 0

#define MAXTIME 60
#define MINTIME .1

// GENERAL ///////////////////////////////////////////////////////////////

//#define TEST

// DRAW //////////////////////////////////////////////////////////////////

static bool BUILD = false;
#define DRAW
#define CLEANSCREEN
//#define DRAWDEBUGINFO

//////////////////////////////////////////////////////////////////////////


/// CANNOT EDIT ///

// DATA DRIVEN ///////////////////////////////////////////////////////////

static std::string DATAPATH = (BUILD ? "data/" : "../data/");
static std::string DEFAULTFILENAMEBOARD = "board";
static std::string DEFAULTFILENAMEPLAYERLIST = "players";

// DRAW //////////////////////////////////////////////////////////////////

#define DRAWBOARDCHAR '+'
#define DRAWPLAYER_NORMALCHAR 'O'
#define DRAWPLAYER_INMORTALCHAR '@'

//////////////////////////////////////////////////////////////////////////
