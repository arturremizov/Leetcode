#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        unordered_map<int, int> top, bottom, left, right;
        
        long long totalSum = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int value = grid[row][col];
                totalSum += value;
                bottom[value]++;
                right[value]++;
            }
        }

        long long topSum = 0;
        for (int row = 0; row < rows - 1; ++row) {
            for (int col = 0; col < cols; ++col) {
                int value = grid[row][col];
                topSum += value;
                top[value]++;
                bottom[value]--;
            }
            
            long long bottomSum = totalSum - topSum;
            if (topSum == bottomSum) return true;
            if (topSum > bottomSum) {
                long long diff = topSum - bottomSum;
                if (canRemove(diff, top, 0, 0, row, cols - 1, grid)) {
                    return true;
                }
            } else {
                long long diff = bottomSum - topSum;
                if (canRemove(diff, bottom, row + 1, 0, rows - 1, cols - 1, grid)) {
                    return true;
                }
            }
        }

        long long leftSum = 0;
        for (int col = 0; col < cols - 1; ++col) {
            for (int row = 0; row < rows; ++row) {
                int value = grid[row][col];
                leftSum += value;
                left[value]++;
                right[value]--;
            }
            
            long long rightSum = totalSum - leftSum;
            if (leftSum == rightSum) return true;
            if (leftSum > rightSum) {
                long long diff = leftSum - rightSum;
                if (canRemove(diff, left, 0, 0, rows - 1, col, grid)) {
                    return true;
                }
            } else {
                long long diff = rightSum - leftSum;
                if (canRemove(diff, right, 0, col + 1, rows - 1, cols - 1, grid)) {
                    return true;
                }
            }
        }

        return false;
    }
private:
    bool canRemove(long long value,
                   unordered_map<int, int>& valueToCountMap,
                   int startRow, int startCol,
                   int endRow, int endCol,
                   vector<vector<int>>& grid) {
                    
        if (value > 1e5) return false;

        int rows = endRow - startRow + 1;
        int cols = endCol - startCol + 1;

        if (rows * cols == 1) return false;

        if (rows == 1) {
            return value == grid[startRow][startCol] || value == grid[startRow][endCol];
        }

        if (cols == 1) {
            return value == grid[startRow][startCol] || value == grid[endRow][startCol];
        }

        return valueToCountMap[value] > 0;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2,4},
        {2,3,5}
    };
    cout << solution.canPartitionGrid(grid) << endl; // false
}