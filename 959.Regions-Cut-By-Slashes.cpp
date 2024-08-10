#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        const int scaledRows = rows * 3, scaledCols = cols * 3;
        vector<vector<int>> scaledGrid(scaledRows, vector<int>(scaledCols));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int scaledRow = row * 3, scaledCol = col * 3;
                if (grid[row][col] == '/') {
                    scaledGrid[scaledRow][scaledCol + 2] = 1;
                    scaledGrid[scaledRow + 1][scaledCol + 1] = 1;
                    scaledGrid[scaledRow + 2][scaledCol] = 1;
                } else if (grid[row][col] == '\\') {
                    scaledGrid[scaledRow][scaledCol] = 1;
                    scaledGrid[scaledRow + 1][scaledCol + 1] = 1;
                    scaledGrid[scaledRow + 2][scaledCol + 2] = 1;
                }
            }
        }

        unordered_set<pair<int, int>, hashFunction> visited;
        int result = 0;
        for (int row = 0; row < scaledRows; ++row) {
            for (int col = 0; col < scaledCols; ++col) {
                if (scaledGrid[row][col] == 0 && !visited.count({row, col})) {
                    dfs(scaledGrid, row, col, visited);
                    ++result;
                }
            }
        }
        return result;        
    }
private:
    struct hashFunction {
        size_t operator()(const pair<int , int> &x) const {
            return x.first ^ x.second;
        }
    };

    void dfs(vector<vector<int>>& grid, int row, int col, unordered_set<pair<int, int>, hashFunction>& visited) {
        const int rows = grid.size(), cols = grid[0].size();
        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid[row][col] != 0 || visited.count({row, col})) {
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
    vector<string> grid = {" /","/ "};
    cout << solution.regionsBySlashes(grid) << endl; // 2
}