#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = rows << cols - 1;
        for (int col = 1; col < cols; ++col) {
            int oneCount = 0;
            for (int row = 0; row < rows; ++row) {
                if (grid[row][col] == grid[row][0]) {
                    ++oneCount;
                }
            }
            int zeroCount = rows - oneCount;
            result += max(oneCount, zeroCount) << (cols - 1 - col);
        }
        return result;


        // for (int row = 0; row < rows; ++row) {
        //     if (grid[row][0] == 0) {
        //         for (int col = 0; col < cols; ++col) {
        //             grid[row][col] = grid[row][col] == 0 ? 1 : 0;
        //         }
        //     }
        // }
        // for (int col = 0; col < cols; ++col) {
        //     int oneCount = 0;
        //     for (int row = 0; row < rows; ++row) {
        //         if (grid[row][col] == 1) {
        //             ++oneCount;
        //         }
        //     }
        //     int zeroCount = rows - oneCount;
        //     if (oneCount < zeroCount) {
        //         for (int row = 0; row < rows; ++row) {
        //             grid[row][col] = grid[row][col] == 0 ? 1 : 0;
        //         }
        //     }
        // }
        // int result = 0;
        // for (int row = 0; row < rows; ++row) {
        //     for (int col = 0; col < cols; ++col) {
        //         result += grid[row][col] << (cols - col - 1);
        //     }
        // }
        // return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };
    cout << solution.matrixScore(grid) << endl; // 39
}