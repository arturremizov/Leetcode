#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1));
        for (int row = 1; row <= rows; ++row) {
            for (int col = 1; col <= cols; ++col) {
                prefixSum[row][col] = prefixSum[row - 1][col]
                                    + prefixSum[row][col - 1]
                                    - prefixSum[row - 1][col - 1]
                                    + mat[row - 1][col - 1];
            }
        }

        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                for (int side = result + 1; row + side <= rows && col + side <= cols; ++side) {
                    int sum = prefixSum[row + side][col + side]
                            - prefixSum[row + side][col]
                            - prefixSum[row][col + side]
                            + prefixSum[row][col];

                    if (sum > threshold) break;

                    result = side;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> mat = {
        {1,1,3,2,4,3,2}, 
        {1,1,3,2,4,3,2},
        {1,1,3,2,4,3,2}
    };
    cout << solution.maxSideLength(mat, 4) << endl; // 2
}