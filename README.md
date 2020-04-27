# The Game Of Life

### Description

Basic game based on "The Game of Life" theory by Conway.
This game tries to study different community configurations, and how they evolve. It's a 0 player game, so given an initial configuration, no further input is required.

The game consists on a board with a number of initial players distributed along the board as the user wants. The goal of this game is to survive as much time as possible, following the next rules:

 - Birth: any dead cell with exactly 3 live neighbours becomes a live cell.
 - Overpopulation: any live cell with more than 3 live neighbours dies by overpopulation.
 - Underpopulation: any live cell with fewer than 2 live neighbours dies by underpopulation.
 - Survive: any live cell with 2 or 3 live neighbours survives on to the next generation.

More Info: https://en.wikipedia.org/wiki/Conway's_Game_of_Life

In this version, whe have the common behaviour of each cell described before, but we also added a new special cell that cannot be eliminated from the board (not by underpopulation and not by overpopulation). We'll call this new cell: "inmortal".

##### Representation

 - Empty (dead) cell: '+'
 - Normal (live) cell: 'O'
 - Inmortal cell: '@'


### Builds

##### Alpha v1.0 & Alpha v1.2

 - PRECONDITION -
Need to have the .exe inside the build folder (f.e. "TGOL_Build v1.0_ALPHA 200418").

 - RUN -
1.- Double click the .exe.

NOTE: the board data and the player(cell) list is predetermined and cannot be changed.


##### Alpha v1.4 & Alpha v1.6 & Alpha v1.8

 - PRECONDITION -
Need to have the .exe inside the build folder (f.e. "TGOL_Build v1.4_ALPHA 200420") and the data to be loaded (for board and player(cell) list) inside a folder called "data" at the same level as the build folder. The data files MUST be called "board.txt" and "players.txt".

 - RUN -
1.- Double click the .exe.


##### Beta v2.0 & Beta v2.2

 - PRECONDITION -
Need to have the .exe inside the build folder (f.e. "TGOL_Build v2.0_BETA 200425"); the game files inside a folder called "game" at the same level as the .exe; and the data to be loaded (for board and player(cell) list) inside a folder called "data" at the same level as the .exe.

 - RUN -
1.- Double click the .exe.
2.- Introduce the name of the files where the data is stored (of press -D- to load default info).
