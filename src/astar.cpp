
#include <iostream>
#include "../include/astar.h"

AStar::AStar() {}

std::vector<Node*> AStar::runAStar(const Map& map, int startX, int startY, int goalX, int goalY) {
    std::cout << "running astar" << "\n";

    Node* dummyNode = new Node(6, 5); 

    std::vector<Node*> path;
    path.push_back(dummyNode);

    return path;
}

