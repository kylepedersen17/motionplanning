#include <iostream>
#include "../include/map.h"

int main() {
    Map map(20, 20);

    map.setStart(0, 0);
    map.setGoal(4, 4);
    map.setObstacle(2, 2);

    map.printMap();


    return 0;
}
