#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int rows = grid.size(), cols = grid[0].size();
        vector minDist = vector(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>> minHeap;

        minHeap.emplace(grid[0][0], 0, 0);

        while (!minHeap.empty()) {
            auto [value, row, col] = minHeap.top();
            minHeap.pop();
            if (minDist[row][col] != INT_MAX) continue;
            minDist[row][col] = value;

            vector<pair<int, int>> neighbors = {
                {row - 1, col}, {row + 1, col},
                {row, col - 1}, {row, col + 1}
            };
            for (auto [neiRow, neiCol] : neighbors) {
                if (min(neiRow, neiCol) < 0 || 
                    neiRow == rows ||
                    neiCol == cols ||
                    minDist[neiRow][neiCol] != INT_MAX) {
                    continue;
                }
                minHeap.emplace(value + grid[neiRow][neiCol], neiRow, neiCol);
            }
        }
        return minDist[rows - 1][cols - 1] < health;
    }   
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,0,0,0},
        {0,1,0,1,0},
        {0,0,0,1,0}
    };
    cout << solution.findSafeWalk(grid, 1) << endl; // true
}