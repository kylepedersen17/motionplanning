#pragma once

#include "map.h" 

struct Node {
    int x;
    int y;
    double gScore;
    double fScore;
    std::unique_ptr<Node> prev;

    Node(int x1, int y1) {
        x = x1;
        y = y1;
        gScore = 0.0;
        fScore = 0.0;
        prev = nullptr;
    }
};

class AStar {
public:
    std::vector<std::unique_ptr<Node>> runAStar(Map& map, int startX, int startY, int goalX, int goalY);

};

