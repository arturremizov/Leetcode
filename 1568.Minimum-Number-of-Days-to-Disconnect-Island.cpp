#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        
        int islands = countIslands(grid);
        if (islands == 0 || islands > 1) return 0;

        const int rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) continue;

                grid[row][col] = 0;

                int newIslands = countIslands(grid);
                if (newIslands != 1) return 1;

                grid[row][col] = 1;
            }
        }
        return 2;
    }
private:
    struct hashFunction {
        size_t operator()(const pair<int , int> &x) const {
            return x.first ^ x.second;
        }
    };

    int countIslands(vector<vector<int>>& grid) {
        int islands = 0;
        unordered_set<pair<int, int>, hashFunction> visited;
        const int rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] && !visited.count({row, col})) {
                    dfs(grid, row, col, visited);
                     ++islands;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, 
             unordered_set<pair<int, int>, hashFunction>& visited) {
        
        const int rows = grid.size(), cols = grid[0].size();
        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid[row][col] == 0 || visited.count({row, col})) {
            return;
        } 
        visited.insert({row, col});

        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row, col + 1},
            {row  - 1, col}, {row, col - 1}
        };
        for (auto [neighborRow, neighborCol] : neighbors) {
            dfs(grid, neighborRow, neighborCol, visited);
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    cout << solution.minDays(grid) << endl; // 2
}