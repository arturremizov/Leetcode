#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] > 0 && !visited[row][col]) {
                    result = max(result, dfs(row,col,grid,visited));
                }
            }
        }
        return result;
    }
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = grid[row][col];
        visited[row][col] = true;
        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row - 1, col},
            {row, col + 1}, {row, col - 1}
        };
        for (auto [neighborRow, neighborCol] : neighbors) {
            if (neighborRow < 0 || neighborCol < 0 || 
                neighborRow == rows || neighborCol == cols ||
                grid[neighborRow][neighborCol] == 0 || 
                visited[neighborRow][neighborCol]) {
                continue;
            }
            result += dfs(neighborRow,neighborCol,grid,visited);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,2,1,0},
        {4,0,0,3},
        {1,0,0,4},
        {0,3,2,0}
    };
    cout << solution.findMaxFish(grid) << endl; // 7
}