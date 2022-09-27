# include <stdint.h>
# include <iostream>
# include <ncurses.h>
# include <utility> 
# include <vector>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
# include "Board.h"

int main(int argc, char *argv[])
{
    Board b;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    time_t seed = (tv.tv_usec ^ (tv.tv_sec << 20)) & 0xffffffff;
    srand(seed);
    init_terminal();
    init_board(&b);
    while(b.aliveShipTiles>0){
        print_real_board(&b);
        mvaddstr(12,0,"Select a y cordinate from 0-9");
        int y =(int) getch() - '0';
        mvprintw(12,0,"(%d, )",y);
        mvaddstr(12,0,"Select a x cordinate from 0-9");
        int x =(int) getch() - '0';
        mvprintw(13,0,"(%d,%d)",y,x);
        if((x<10&&x>=0)&&(y<10&&y>=0)){
            if(b.gameBoard[y][x] == SEA){
                b.gameBoard[y][x] = HIT_SEA;
            }
            else if(b.gameBoard[y][x] == SHIP){
                b.gameBoard[y][x] = HIT_SHIP;
                b.aliveShipTiles--;
            }
            else{
                mvaddstr(12,0,"Already hit, try again.");
            }
        }
    }
    endwin();
    return 0;
}