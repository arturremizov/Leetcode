#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        long long totalSum = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                totalSum += grid[row][col];
            }
        }

        if (totalSum % 2 == 1) return false;

        long long target = totalSum / 2;
        long long curSum = 0;
        for (int row = 0; row < rows - 1; ++row) {
            for (int col = 0; col < cols; ++col) {
                curSum += grid[row][col];
            }
            if (curSum == target) return true;
        }

        curSum = 0;
        for (int col = 0; col < cols - 1; ++col) {
            for (int row = 0; row < rows; ++row) {
                curSum += grid[row][col];
            }
            if (curSum == target) return true;
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,4},
        {2,3}
    };
    cout << solution.canPartitionGrid(grid) << endl; // true
}