#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    struct hashFunction {
        size_t operator()(const pair<int , int> &x) const {
            return x.first ^ x.second;
        }
    };
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (min(grid[0][1], grid[1][0]) > 1) return -1;

        const int rows = grid.size(), cols = grid[0].size();
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> minHeap; // time, row, col
        minHeap.push({0,0,0});

        unordered_set<pair<int,int>, hashFunction> visited;
        visited.insert({0,0});

        while (!minHeap.empty()) {
            auto [time, row, col] = minHeap.top();
            minHeap.pop();
            if (row == rows - 1 && col == cols - 1) return time;
            vector<pair<int, int>> neigbors = {
                {row + 1, col},
                {row, col + 1},
                {row - 1, col},
                {row, col - 1}
            };
            for (auto [neigborRow, neigborCol] : neigbors) {
                if (visited.count({neigborRow, neigborCol}) ||
                    neigborRow < 0 || neigborCol < 0 || neigborRow == rows || neigborCol == cols) {
                    continue;
                }
                int waitTime = 0;
                if (abs(grid[neigborRow][neigborCol] - time) % 2 == 0) {
                    waitTime = 1;
                }
                int nextTime = max(grid[neigborRow][neigborCol] + waitTime, time + 1);
                minHeap.push({nextTime, neigborRow, neigborCol});
                visited.insert({neigborRow, neigborCol});
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,3,2},
        {5,1,2,5},
        {4,3,8,6}
    };
    cout << solution.minimumTime(grid) << endl; // 7
}