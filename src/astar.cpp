
#include <iostream>
#include "../include/astar.h"

AStar::AStar() {}

std::vector<Node*> AStar::runAStar(const Map& map, int startX, int startY, int goalX, int goalY) {
    std::cout << "running astar" << "\n";

    Node* node1 = new Node(6, 5);
    Node* node2 = new Node(7, 8);
    node2->cameFrom = node1;

    std::vector<Node*> path;
    path.push_back(node1);
    path.push_back(node2);

    return path;
}

