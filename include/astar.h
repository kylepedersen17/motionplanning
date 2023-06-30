#pragma once

#include "map.h" 

struct Node {
    int x;
    int y;
    double gScore;
    double fScore;
    Node* cameFrom;

    Node(int x1, int y1) {
        x = x1;
        y = y1;
        gScore =0.0;
        fScore = 0.0;
        cameFrom = nullptr;
    }
};

class AStar {
public:
    AStar();

    std::vector<Node*> runAStar(const Map& map, int startX, int startY, int goalX, int goalY);

private:
    double calculateHeuristic(int x1, int y1, int x2, int y2);
    std::vector<Node*> reconstructPath(Node* goalNode);
};

