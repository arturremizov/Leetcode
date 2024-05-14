#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                result = max(result, dfs(grid, row, col));
            }
        }
        return result;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        const int rows = grid.size(), cols = grid[0].size();
        if (min(row, col) < 0 || row == rows || col == cols || 
            grid[row][col] == 0) {
            return 0;
        }
        int tmpValue = grid[row][col];
        grid[row][col] = 0;
        int result = 0;
        vector<pair<int, int>> neighbors = { 
            {row + 1, col},
            {row - 1, col},
            {row, col + 1},
            {row, col - 1}
        };
        for (auto neigbor : neighbors) {
            result = max(result, tmpValue + dfs(grid, neigbor.first, neigbor.second));
        }
        grid[row][col] = tmpValue;
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };
    cout << solution.getMaximumGold(grid) << endl; // 24
}