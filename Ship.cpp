# include <stdint.h>
# include <iostream>
# include <utility> 
# include <vector>
# include "Board.h"


Ship::Ship(int l, std::vector<std::pair <int,int>> cord)
{
    length=l;
    currentHealth=l;
    cordinates = cord;
}

void takeHit(Ship s, std::pair<int,int> cord){
    s.currentHealth--;
}

bool Ship::isSunk(){
    if(currentHealth<=length){
        return true;
    }
    return false;
}