#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const unordered_map<int, pair<int, int>> directions = {
            {1, {0,1}},
            {2, {0,-1}},
            {3, {1, 0}},
            {4, {-1, 0}}
        };

        const int rows = grid.size(), cols = grid[0].size();

        deque<tuple<int, int, int>> queue { {0,0,0} }; // row, col, cost
        unordered_map<string, int> minCost { {"0,0", 0} }; 
        while (!queue.empty()) {
            auto [row, col, cost] = queue.front();
            queue.pop_front();

            if (row == rows - 1 && col == cols - 1) {
                return cost;
            }

            for (auto direction : directions) {
                auto [directionRow, directionCol] = direction.second;
                int neighborRow = row + directionRow;
                int neighborCol = col + directionCol;
                int neighborCost = direction.first == grid[row][col] ? cost : cost + 1;

                string minCostKey = to_string(neighborRow) + "," + to_string(neighborCol);
                if (neighborRow < 0 || neighborCol < 0 || 
                    neighborRow == rows || neighborCol == cols || 
                    (minCost.count(minCostKey) && neighborCost >= minCost[minCostKey])) {
                    continue;
                }

                minCost[minCostKey] = neighborCost;
                if (direction.first == grid[row][col]) {
                    queue.push_front({neighborRow, neighborCol, neighborCost});
                } else {
                    queue.push_back({neighborRow, neighborCol, neighborCost});
                }

            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,1,1,1},
        {2,2,2,2},
        {1,1,1,1},
        {2,2,2,2}
    }; 
    cout << solution.minCost(grid) << endl; // 3
}