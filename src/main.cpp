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
    
    BFS bfs;
    std::vector<std::pair<int, int>> path = bfs.runBFS(map, adjacencyList, map.getStart(), map.getGoal());

    std::cout << "Path from start to goal: " << std::endl;
    for (auto step : path) {
        std::cout << "(" << step.first << ", " << step.second << ") ";
    }
    std::cout << std::endl;
}
