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
    int minimumObstacles(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> minHeap; // obstacles, row, col
        minHeap.push({0, 0, 0});

        unordered_set<pair<int,int>, hashFunction> visited;
        visited.insert({0, 0});

        while (!minHeap.empty()) {
            auto [obstacles, row, col] = minHeap.top();
            minHeap.pop();
            if (row == rows - 1 && col == cols - 1) return obstacles;
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
                minHeap.push({obstacles + grid[neigborRow][neigborCol], neigborRow, neigborCol});
                visited.insert({neigborRow, neigborCol});
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,1},
        {1,1,0},
        {1,1,0}
    };
    cout << solution.minimumObstacles(grid) << endl; // 2
}