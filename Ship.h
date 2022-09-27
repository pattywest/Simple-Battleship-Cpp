# include <stdint.h>
# include <iostream>
# include <utility> 
# include <vector>

class Ship {
 public:
    char direction;
    int length;
    int currentHealth;
    std::vector<std::pair <int,int>> cordinates;

    Ship(int l, std::vector<std::pair <int,int>> cord);

    void takeHit(Ship s, std::pair<int,int> cord);

    bool isSunk();
};