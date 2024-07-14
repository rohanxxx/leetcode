/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */


#include <vector>
#include <set>
#include <utility>

class Solution {
    // Going clockwise: 0: 'up', 1: 'right', 2: 'down', 3: 'left'
    std::vector<std::vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    std::set<std::pair<int, int>> visited;
    Robot* robot;

public:
    void goBack() {
        robot->turnRight();
        robot->turnRight();
        robot->move();
        robot->turnRight();
        robot->turnRight();
    }

    void backtrack(int row, int col, int d) {
        visited.insert({row, col});
        robot->clean();
        // Going clockwise: 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];

            if (visited.find({newRow, newCol}) == visited.end() && robot->move()) {
                backtrack(newRow, newCol, newD);
                goBack();
            }
            // Turn the robot following the chosen direction: clockwise
            robot->turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        this->robot = &robot;
        backtrack(0, 0, 0);
    }
};
