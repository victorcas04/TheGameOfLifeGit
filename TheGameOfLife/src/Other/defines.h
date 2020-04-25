#pragma once

#include <string>

//////////////////////////////////////////////////////////////////////////
// CAN EDIT //////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// GENERAL ///////////////////////////////////////////////////////////////

//#define TEST

// DRAW //////////////////////////////////////////////////////////////////

static bool BUILD = true;
#define DRAW
#define CLEANSCREEN
//#define DRAWDEBUGINFO

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// CANNOT EDIT ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// DATA DRIVEN ///////////////////////////////////////////////////////////

static std::string DATAPATH = (BUILD ? "data/" : "../data/");
static std::string DEFAULTFILENAMEBOARD = "board";
static std::string DEFAULTFILENAMEPLAYERLIST = "players";

// DRAW //////////////////////////////////////////////////////////////////

#define DRAWBOARDCHAR '+'
#define DRAWPLAYER_NORMALCHAR 'O'
#define DRAWPLAYER_INMORTALCHAR '@'

//////////////////////////////////////////////////////////////////////////
