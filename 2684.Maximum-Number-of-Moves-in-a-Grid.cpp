#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        unordered_map<string, int> memo;
        for (int row = 0; row < rows; ++row) {
            result = max(result, helper(grid, row, 0, memo));
        }
        return result;
    }
private:
    int helper(vector<vector<int>>& grid, int row, int col, unordered_map<string, int>& memo) {
        string key = to_string(row) + "," + to_string(col);
        if (memo.count(key)) return memo[key];

        const int rows = grid.size(), cols = grid[0].size();

        vector<pair<int, int>> neighbors = {
            {row - 1, col + 1},{row, col + 1},{row + 1, col + 1}
        };
        int result = 0;
        for (auto [neighborRow, neighborCol] : neighbors) {
            if (neighborRow >= 0 && neighborRow < rows && neighborCol < cols && 
                grid[row][col] < grid[neighborRow][neighborCol]) {

                result = max(result, 1 + helper(grid, neighborRow, neighborCol, memo));
            }
        }
        memo[key] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {2,4,3,5},
        {5,4,9,3},
        {3,4,2,11},
        {10,9,13,15}
    };
    cout << solution.maxMoves(grid) << endl; // 3
}