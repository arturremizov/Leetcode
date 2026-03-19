#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<int> colXCount(cols), colYCount(cols);
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            int xSum = 0, ySum = 0;
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 'X') {
                    colXCount[col]++;
                } else if (grid[row][col] == 'Y') {
                    colYCount[col]++;
                }
                xSum += colXCount[col];
                ySum += colYCount[col];
                if (xSum > 0 && xSum == ySum) {
                    ++result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<char>> grid = {
        {'X','Y','.'},
        {'Y','.','.'}
    };
    cout << solution.numberOfSubmatrices(grid) << endl; // 3
}