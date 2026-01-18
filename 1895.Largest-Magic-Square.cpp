#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> rowSum(rows, vector<int>(cols + 1));
        vector<vector<int>> colSum(rows + 1, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                rowSum[row][col + 1] = rowSum[row][col] + grid[row][col];
                colSum[row + 1][col] = colSum[row][col] + grid[row][col];
            }
        }

        for (int side = min(rows, cols); side >= 2; --side) {
            for (int row = 0; row + side <= rows; ++row) {
                for (int col = 0; col + side <= cols; ++col) {
                    int target = rowSum[row][col + side] - rowSum[row][col];
                    bool isValid = true;

                    // check rows 
                    for (int r = 1; r < side; ++r) {
                        int sum = rowSum[row + r][col + side] - rowSum[row + r][col];
                        if (sum != target) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid) continue;

                    // check cols
                    for (int c = 0; c < side; ++c) {
                        int sum = colSum[row + side][col + c] - colSum[row][col + c];
                        if (sum != target) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid) continue;

                    // check diagonal
                    int diagSum1 = 0, diagSum2 = 0;
                    for (int i = 0; i < side; ++i) {
                        diagSum1 += grid[row + i][col + i];
                        diagSum2 += grid[row + side - i - 1][col + i];
                    }

                    if (diagSum1 != target || diagSum2 != target) continue;

                    return side;
                }
            }
        }
        return 1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {7,1,4,5,6}, 
        {2,5,1,6,4},
        {1,5,4,3,2},
        {1,2,7,3,4}
    };
    cout << solution.largestMagicSquare(grid) << endl; // 3
}