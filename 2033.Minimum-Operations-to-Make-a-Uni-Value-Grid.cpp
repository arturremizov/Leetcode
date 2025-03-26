#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int n = grid.size(), m = grid[0].size();
        int remander = grid[0][0] % x;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] % x != remander) {
                    return -1;
                }
            }
        } 

        int total = 0;
        vector<int> nums;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                nums.push_back(grid[row][col]);
                total += grid[row][col];
            }
        } 
        sort(nums.begin(), nums.end());

        int prefix = 0;
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int costLeft = nums[i] * i - prefix;
            int costRight = total - prefix - (nums[i] * (nums.size() - i));
            int operations = (costLeft + costRight) / x;
            result = min(result, operations);
            prefix += nums[i];
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {{2,4},{6,8}};
    cout << solution.minOperations(grid, 2) << endl; // 4
}