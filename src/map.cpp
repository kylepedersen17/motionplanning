#include <iostream>
#include <vector>
#include "map.h"


// Constructor -- initialize grid map w/ given size and mark all cells as free
Map::Map(int width, int height) {
    grid = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    _height = height;
    _width = width;
}

// set obstacle at specified location
void Map::setObstacle(int x, int y) {
    grid[y][x] = 1;
}

// set start pt.
void Map::setStart(int x, int y) {
    start = {x, y};
    grid[y][x] = 2;
}

// set goal pt.
void Map::setGoal(int x, int y) {
    goal = {x, y};
    grid[y][x] = 2;
}

// get start pt.
std::pair<int, int> Map::getStart() {
    return start;
}

// get goal pt.
std::pair<int, int> Map::getGoal() {
    return goal;
}

// check if cell is free (not an obstacle)
bool Map::isFree(int x, int y) {
    return grid[y][x] == 0;
}

int Map::getValue(int x, int y) {
    return grid[y][x];
}

std::unordered_map<int, std::vector<int>> Map::makeAdjacencyList() {

    std::unordered_map<int, std::vector<int>> list; //coordinate id to list of coordinate neighbor ids
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++)  {
            if (getValue(x, y) == 1) continue; // skip if obstacle 

            int hash = encodeHash(x, y);
            std::vector<int> neighbors;
            
            //check down, up, left, and right neighbors (only 4 possible)

            //down
            if (y + 1 < _height && getValue(x, y + 1) != 1) {
                neighbors.push_back(encodeHash(x, y + 1));
            }

            //up 
            if (y > 0 && getValue(x, y - 1) != 1) {
                neighbors.push_back(encodeHash(x, y - 1));
            }

            //left
            if (x > 0 && getValue(x - 1, y) == 0) {
                    neighbors.push_back(encodeHash(x - 1, y));
            }

            //right 
            if (x + 1 < _width && getValue(x + 1, y) != 1) {
                neighbors.push_back(encodeHash(x + 1, y));
            }

            list[hash] = neighbors; //add to hashmap

        }
    }
    return list;
}

// print map.
void Map::printMap() {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

int Map::encodeHash(int x, int y) {
    return y * _width + x;
}

std::pair<int, int> Map::decodeHash(int hash) {
        int y = hash / _width;
        int x = hash % _width;
        return std::make_pair(x, y);
}

