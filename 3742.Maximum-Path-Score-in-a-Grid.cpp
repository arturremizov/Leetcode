#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int rows = 0, cols = 0;
    int limit = 0;
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        rows = grid.size(), cols = grid[0].size();
        limit = k;
        vector memo(rows, vector(cols, vector<int>(k + 1, -2)));
        return dfs(0, 0, 0, grid, memo);
    }
private:
    int dfs(int row,
            int col,
            int cost,
            vector<vector<int>>& grid,
            vector<vector<vector<int>>>& memo) {

        if (cost > limit) return -1;
        if (row == rows - 1 && col == cols - 1) return 0;
        if (memo[row][col][cost] != -2) return memo[row][col][cost];

        int result = -1;
        static const vector<pair<int, int>> directions = {{1, 0}, {0, 1}};  
        for (auto [dr, dc] : directions) {
            int nextRow = row + dr;
            int nextCol = col + dc;
            if (nextRow == rows || nextCol == cols) continue;

            int value = grid[nextRow][nextCol];
            int addCost = value != 0;
            int curResult = dfs(nextRow, nextCol, cost + addCost, grid, memo);
            if (curResult != -1) {
                result = max(result, curResult + value);
            }
        }

        return memo[row][col][cost] = result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1},
        {2,0}
    };
    cout << solution.maxPathScore(grid, 1) << endl; // 2
}