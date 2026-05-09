#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector result = vector(rows, vector<int>(cols));
        int layers = min(rows, cols) / 2;
        for (int layer = 0; layer < layers; ++layer) {
            vector<int> nums;
            int top = layer;
            int bottom = rows - layer - 1;
            int left = layer;
            int right = cols - layer - 1; 
            // top
            for (int col = left; col < right; ++col) {
                nums.push_back(grid[top][col]);
            }
            // right 
            for (int row = top; row < bottom; ++row) {
                nums.push_back(grid[row][right]);
            }
            // bottom 
            for (int col = right; col > left; --col) {
                nums.push_back(grid[bottom][col]);
            }
            // left 
            for (int row = bottom; row > top; --row) {
                nums.push_back(grid[row][left]);
            }

            int numsTotal = nums.size();
            int i = k % numsTotal;
            // top
            for (int col = left; col < right; ++col) {
                result[top][col] = nums[i++ % numsTotal];
            }
            // right 
            for (int row = top; row < bottom; ++row) {
                result[row][right] = nums[i++ % numsTotal];
            }
            // bottom 
            for (int col = right; col > left; --col) {
                result[bottom][col] = nums[i++ % numsTotal];
            }
            // left 
            for (int row = bottom; row > top; --row) {
                result[row][left] = nums[i++ % numsTotal];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<vector<int>> result = solution.rotateGrid(grid, 2); // [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
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