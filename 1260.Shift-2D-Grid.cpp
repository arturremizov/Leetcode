#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector result(rows, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int position = row * cols + col; // convert to 1D 
                int shiftedPosition = (position + k) % (rows * cols); // convert back to 2D
                int shiftedRow = shiftedPosition / cols;
                int shiftedCol = shiftedPosition % cols;
                result[shiftedRow][shiftedCol] = grid[row][col];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> result = solution.shiftGrid(grid, 1); // [[9,1,2],[3,4,5],[6,7,8]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}