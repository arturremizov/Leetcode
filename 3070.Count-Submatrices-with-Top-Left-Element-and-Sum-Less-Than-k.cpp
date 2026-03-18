#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<int> colSum(cols);
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            int rowSum = 0;
            for (int col = 0; col < cols; ++col) {
                colSum[col] += grid[row][col];
                rowSum += colSum[col];
                if (rowSum <= k) {
                    ++result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {7,2,9},
        {1,5,0},
        {2,6,6}
    };
    cout << solution.countSubmatrices(matrix, 20) << endl; // 6
}