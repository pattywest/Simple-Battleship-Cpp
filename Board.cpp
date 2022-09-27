# include <stdint.h>
# include <iostream>
# include <ncurses.h>
# include <utility> 
# include <vector>
# include "Board.h"

void init_terminal(){
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  start_color();
  init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
}

void init_board(Board *b){
    int finishedBuild = 0;
    while(finishedBuild == 0){
        finishedBuild = genBoard(b);
    }
}
int genBoard(Board *b){
    b->aliveShipTiles = 10;
    int randCount = 0;
    for(int y = 0;y<10;y++){
        for(int x = 0;x<10;x++){
            b->gameBoard[y][x] = SEA;
        }
    }
    int numOfShipTiles = 10;
    while(numOfShipTiles > 0){
        int ok = 0;
        int lenOfShip = 0;
        while(ok == 0){
            if(randCount > 20){
                return 0;
            }
            lenOfShip = rand() % 2 + 2;
            if(lenOfShip <= numOfShipTiles){
                ok = genShips(lenOfShip, b);
            }
            randCount++;
        }
        numOfShipTiles -= lenOfShip;
    }
    return 1;
}
int genShips(int lenOfShip, Board *b){

    int direction = rand() % 4;
    int posX = rand() % 10, posY = rand() % 10;
    //north
    if(direction == 0){
        if(posY - lenOfShip < 0){
            return 0;
        }
        for(int i=0; i<lenOfShip; i++){
            if(b->gameBoard[posY - i][posX] == 1){
                return 0;
            }
        }
        for(int j=0; j<lenOfShip; j++){
            b->gameBoard[posY - j][posX] = 1;
        }
        return 1;
    }
        //south
    else if(direction == 1){
        if(posY + lenOfShip > 9){
            return 0;
        }
        for(int i=0; i<lenOfShip; i++){
            if(b->gameBoard[posY + i][posX] == 1){
                return 0;
            }
        }

        for(int j=0; j<lenOfShip; j++){
            b->gameBoard[posY + j][posX] = 1;
        }
        return 1;
    }
        //east
    else if(direction == 2){
        if(posX + lenOfShip > 9){
            return 0;
        }
        for(int i=0; i<lenOfShip; i++){
            if(b->gameBoard[posY][posX + i] == 1){
                return 0;
            }
        }
        for(int j=0; j<lenOfShip; j++){
            b->gameBoard[posY][posX + j] = 1;
        }
        return 1;
    }
        //west
    else{
        if(posX - lenOfShip < 0){
            return 0;
        }
        for(int i=0; i<lenOfShip; i++){
            if(b->gameBoard[posY][posX - 1] == 1){
                return 0;
            }
        }
        for(int j=0; j<lenOfShip; j++){
            b->gameBoard[posY][posX - j] = 1;
        }
        return 1;
    }
}

void print_real_board(Board *b){
    uint32_t y, x;
    clear();
    for(y = 0;y<10;y++){
        for(x = 0;x<10;x++){
            if(b->gameBoard[y][x] == SEA){
                attron(COLOR_PAIR(COLOR_BLUE));
                mvaddch(y + 1, x, '~');
                attroff(COLOR_PAIR(COLOR_BLUE));
            }
            else if(b->gameBoard[y][x] == HIT_SHIP){
                attron(COLOR_PAIR(COLOR_RED));
                mvaddch(y + 1, x, 'X');
                attroff(COLOR_PAIR(COLOR_RED));
            }
            else if(b->gameBoard[y][x] == HIT_SEA){
                attron(COLOR_PAIR(COLOR_BLUE));
                mvaddch(y + 1, x, 'O');
                attroff(COLOR_PAIR(COLOR_BLUE));
            }
            else{
                attron(COLOR_PAIR(COLOR_BLUE));
                mvaddch(y + 1, x, '~');
                attroff(COLOR_PAIR(COLOR_BLUE));
            }
        }
    }
    refresh();
}