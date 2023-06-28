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
