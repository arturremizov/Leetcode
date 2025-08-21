#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) continue;
                heights[row][col] = 1;
                if (row > 0) {
                    heights[row][col] += heights[row - 1][col];
                }
            }
        }
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) continue;
                int minHeight = INT_MAX;
                for (int curCol = col; curCol >= 0; --curCol) {
                    if (mat[row][curCol] == 0) break;
                    minHeight = min(minHeight, heights[row][curCol]);
                    result += minHeight;
                }                
            }
        }
        return result;
    } 
};

int main() {
    Solution solution; 
    vector<vector<int>> mat = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    cout << solution.numSubmat(mat) << endl; // 13
}