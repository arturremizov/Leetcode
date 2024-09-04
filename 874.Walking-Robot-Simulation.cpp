#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // N, E, S, W
        int direction = 0;
        int result = 0;

        unordered_set<string> obstaclesSet;
        for (auto& obstacle : obstacles) {
            obstaclesSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        for (int command : commands) {
            if (command == -1) { 
                direction = (direction + 1) % 4;
            } else if (command == -2) {
                direction = (direction + 3) % 4;
            } else {
                int direction_x = directions[direction][0];
                int direction_y = directions[direction][1];
                for (int i = 0; i < command; i++) {
                    if (obstaclesSet.count(to_string(x + direction_x) + "," + to_string(y + direction_y))) {
                        break;
                    }
                    x = x + direction_x;
                    y = y + direction_y;
                }
            }
            result = max(result, x * x + y * y);
        }        
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    cout << solution.robotSim(commands, obstacles) << endl; // 65
}