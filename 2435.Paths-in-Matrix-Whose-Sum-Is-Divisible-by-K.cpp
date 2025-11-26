#include <iostream>
#include <vector>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> memo(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        return dfs(0, 0, 0, grid, k, memo);
    }
private:
    int dfs(int row, int col, int remainder, 
        vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& memo) {

        const int rows = grid.size(), cols = grid[0].size();
        if (row == rows || col == cols) return 0;
        if (memo[row][col][remainder] != -1) return memo[row][col][remainder];
        
        int newRemainder = (remainder + grid[row][col]) % k;
        if (row == rows - 1 && col == cols - 1) return newRemainder == 0 ? 1 : 0;
        
        memo[row][col][remainder] = (dfs(row + 1, col, newRemainder, grid, k, memo) % MOD + 
                                     dfs(row, col + 1, newRemainder, grid, k, memo) % MOD) % MOD;
        return memo[row][col][remainder];
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {5,2,4},
        {3,0,5},
        {0,7,2}
    };
    cout << solution.numberOfPaths(grid, 3) << endl; // 2
}