#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (visited[row][col]) continue;
                if (dfs(row, col, -1, -1, visited, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(int row, int col,
             int prevRow, int prevCol,
             vector<vector<bool>>& visited,
             vector<vector<char>>& grid) {

        const int rows = grid.size(), cols = grid[0].size();

        visited[row][col] = true;

        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row - 1, col},
            {row, col + 1}, {row, col - 1}
        };
        for (auto [neighborRow, neighborCol] : neighbors) {
            if (neighborRow < 0 || neighborRow == rows ||
                neighborCol < 0 || neighborCol == cols || 
                (neighborRow == prevRow && neighborCol == prevCol) ||
                grid[row][col] != grid[neighborRow][neighborCol]) {
                    
                continue;
            } 

            if (visited[neighborRow][neighborCol]) return true;

            if (dfs(neighborRow, neighborCol, row, col, visited, grid)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'c','c','c','a'},
        {'c','d','c','c'},
        {'c','c','e','c'},
        {'f','c','c','c'}
    };
    cout << solution.containsCycle(grid) << endl; // true
}
