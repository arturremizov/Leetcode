#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int top = rows, bottom = 0, left = cols, right = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) continue;
                top = min(top, row);
                bottom = max(bottom, row);
                left = min(left, col);
                right = max(right, col);
            }
        }
        return (bottom - top + 1) * (right - left + 1);
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,0},
        {1,0,1}
    };
    cout << solution.minimumArea(grid) << endl; // 6
}