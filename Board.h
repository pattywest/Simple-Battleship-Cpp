# include <stdint.h>
# include <iostream>
# include <utility> 
# include <vector>
# include "Ship.h"

#define BOARD_X             10
#define BOARD_Y             10

#define SEA                 0
#define SHIP                1
#define HIT_SEA             2
#define HIT_SHIP            9

class Board{
public:
    int gameBoard[BOARD_X][BOARD_Y];
    std::vector<Ship> ships;
    int aliveShipTiles;
    std::pair<int,int> cursor;
};

void init_terminal();
void init_board(Board *b);
void print_real_board(Board *b);
int genShips(int lenOfShip, Board *b);
int genBoard(Board *b);