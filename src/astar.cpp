#include <iostream>
#include "../include/astar.h"

#include <queue>
#include <vector>
#include <unordered_map>

std::vector<std::pair<int, int>> BFS::runBFS(Map& map, std::unordered_map<int, std::vector<int>>& adjacencyList, std::pair<int, int> start, std::pair<int, int> goal) {

    std::queue<int> queue;
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, int> parent;

    int startID = map.encodeHash(start.first, start.second);
    int goalID = map.encodeHash(goal.first, goal.second);

    visited[startID] = true;
    queue.push(startID);
    bool goalReached = false;

    while(!queue.empty()) {
        int nodeID = queue.front();
        queue.pop();
        if (nodeID == goalID) {
            goalReached = true;
            break;
        }

        for (int neighborID : adjacencyList[nodeID]) {
            if (!visited[neighborID]) {
                visited[neighborID] = true;
                parent[neighborID] = nodeID;
                queue.push(neighborID);
            }
        }
    }

    //path reconstruction
    std::vector<std::pair<int, int>> path;
    if (!goalReached) {
        std::cout << "No path found for BFS" << std::endl;
        return path;
    } 
    
    int currNodeID = goalID;
    while(currNodeID != startID) {
        auto [x, y] = map.decodeHash(currNodeID);
        path.push_back(std::make_pair(x, y));
        currNodeID = parent[currNodeID];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    
    return path;
}
