#include <iostream>
#include "../include/map.h"
#include "../include/astar.h"

int main() {
    Map map(20, 20);

    map.setStart(0, 0);
    map.setGoal(4, 4);
    map.setObstacle(2, 2);

    int startX = map.getStart().first;
    int startY = map.getStart().second;
    int goalX = map.getGoal().first;
    int goalY = map.getGoal().second;

    AStar astar;
    std::vector<Node*> path = astar.runAStar(map, startX, startY, goalX, goalY);

    std::cout << "Node: x=" << path[0]->x << ", y=" << path[0]->y << std::endl;

    for (Node* node : path) {
        delete node;
    }
    
    path.clear();

}
