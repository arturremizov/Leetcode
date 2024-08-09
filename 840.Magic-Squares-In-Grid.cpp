#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        for (int row = 0; row < rows - 2; ++row) {
            for (int col = 0; col < cols - 2; ++col) {
                if (magic(grid, row, col)) {
                    ++result;
                }
            }
        }
        return result;
    }
private: 
    bool magic(vector<vector<int>>& grid, int row, int col) {
        // contain numbers from 1 to 9
        unordered_set<int> numbers;
        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                int num = grid[i][j];
                if (numbers.count(num) || !(num >= 1 && num <= 9)) {
                    return false;
                }
                numbers.insert(num);
            }
        }

        // rows sum 
        for (int i = row; i < row + 3; ++i) {
            if (reduce(grid[i].begin() + col, grid[i].begin() + col + 3) != 15) {
                return false;
            }
        }

        // cols sum 
        for (int i = col; i < col + 3; ++i) {
            if ((grid[row][i] + grid[row+1][i] + grid[row+2][i]) != 15) {
                return false;
            }
        }

        // diagonals sum
        if (
            (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2]) != 15 && 
            (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col]) != 15) {
            
            return false;
        }

        return true;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {4,3,8,4},
        {9,5,1,9},
        {2,7,6,2}
    };
    cout << solution.numMagicSquaresInside(grid) << endl; // 1
}