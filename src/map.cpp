#include <iostream>
#include <vector>

class Map {
private:
    std::vector<std::vector<int>> grid;
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
};

// Constructor -- initialize grid map w/ given size and mark all cells as free
Map::Map(int width, int height) {
    grid = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
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

// print map.
void Map::printMap() {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}
