#pragma once

#include "map.h" 
#include <unordered_map>

class BFS {
public:
    std::vector<std::pair<int, int>> runBFS(Map& map, std::unordered_map<int, std::vector<int>>& adjacencyList, std::pair<int, int> start, std::pair<int, int> goal);

};

