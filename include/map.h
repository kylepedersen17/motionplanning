#pragma once

#include <vector>

class Map {
private:
    std::vector<std::vector<int>> grid;
    int _width;
    int _height;
    std::pair<int, int> start;
    std::pair<int, int> goal;

public:
    Map(int width, int height);
    void setObstacle(int x, int y);
    void setStart(int x, int y);
    void setGoal(int x, int y);
    std::pair<int, int> getStart();
    std::pair<int, int> getGoal();
    bool isFree(int x, int y);
    void printMap();
    std::unordered_map<int, std::vector<int>> makeAdjacencyList();
    int encodeHash(int x, int y);
    std::pair<int, int> decodeHash(int hash);
    int getValue(int x, int y);

    void printAdjacencyList(Map& map, std::unordered_map<int, std::vector<int>>& adjacencyList);

};
