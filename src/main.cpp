#include <iostream>
#include "../include/map.h"
#include "../include/astar.h"

int main() {

    int height = 4;
    int width = 4;

    Map map(height, width);

    map.setStart(0, 0);
    map.setGoal(height - 1, width - 1);

    map.setObstacle(2, 3);
    map.setObstacle(1, 1);
    map.setObstacle(1, 2);
    map.setObstacle(3, 1);
    map.setObstacle(0, 3);

    map.printMap();
    std::unordered_map<int, std::vector<int>> adjacencyList = map.makeAdjacencyList();

    for (const auto& pair : adjacencyList) {
            auto [nodeX, nodeY] = map.decodeHash(pair.first); // Decode the node hash
            std::cout << "Node (" << nodeX << ", " << nodeY << ") has neighbors: ";

            for (int neighborHash : pair.second) {
                auto [neighborX, neighborY] = map.decodeHash(neighborHash); // Decode each neighbor hash
                std::cout << "(" << neighborX << ", " << neighborY << ") ";
            }
            std::cout << std::endl;
    }

    // int startX = map.getStart().first;
    // int startY = map.getStart().second;
    // int goalX = map.getGoal().first;
    // int goalY = map.getGoal().second;

    // AStar astar;
    // std::vector<std::unique_ptr<Node>> path = astar.runAStar(map, startX, startY, goalX, goalY);

}
