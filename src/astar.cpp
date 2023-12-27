
#include <iostream>
#include "../include/astar.h"


std::vector<std::unique_ptr<Node>> AStar::runAStar(Map& map, int startX, int startY, int goalX, int goalY) {

    std::cout << "running astar" << "\n";

    std::cout << "--------------------------------" << "\n";
    map.printMap();
    std::cout << "--------------------------------" << "\n";

    
    std::unique_ptr<Node> node1 = std::make_unique<Node>(6, 5);
    std::unique_ptr<Node> node2 = std::make_unique<Node>(7, 99);


    std::vector<std::unique_ptr<Node>> path;
    path.push_back(std::move(node1));
    path.push_back(std::move(node2));

    return path;
}

