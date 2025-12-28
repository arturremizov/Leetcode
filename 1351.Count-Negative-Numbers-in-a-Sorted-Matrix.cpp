#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] < 0) {
                    result += cols - col;
                    break;
                } 
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {4,3,2,-1},
        {3,2,1,-1}, 
        {1,1,-1,-2}, 
        {-1,-1,-2,-3}
    };
    cout << solution.countNegatives(grid) << endl; // 8
}