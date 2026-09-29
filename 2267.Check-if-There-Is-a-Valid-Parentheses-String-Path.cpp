#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] != '(' || grid[rows - 1][cols - 1] != ')') {
            return false;
        }
        int maxCount = rows + cols - 1;
        // 0 - not visited, 1 - has path, 2 - no path
        vector<vector<vector<int>>> memo(rows, vector(cols, vector(maxCount, 0)));
        return dfs(0, 0, 1, grid, memo);
    }
private:
    bool dfs(int row, int col, int count, 
             vector<vector<char>>& grid, 
             vector<vector<vector<int>>>& memo) {

        if (count < 0) return false;
        const int rows = grid.size(), cols = grid[0].size();
        if (row == rows - 1 && col == cols - 1) {
            return count == 0;
        }
        if (memo[row][col][count] != 0) {
            return memo[row][col][count] == 1;
        }

        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row, col + 1}
        };
        bool hasPath = false;
        for (auto [neiRow, neiCol] : neighbors) {
            if (neiRow == rows || neiCol == cols) {
                continue;
            }  
            int newCount = count + (grid[neiRow][neiCol] == '(' ? 1 : -1);
            if (dfs(neiRow, neiCol, newCount, grid, memo)) {
                hasPath = true;
                break;
            }
        }
        memo[row][col][count] = hasPath ? 1 : 2;
        return hasPath;
    }
};

int main() {
    Solution solution; 
    vector<vector<char>> grid = {
        {'(','(','('},
        {')','(',')'},
        {'(','(',')'},
        {'(','(',')'},
    };
    cout << solution.hasValidPath(grid) << endl; // true
}