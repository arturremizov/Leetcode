#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        set<int, greater<int>> sums;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                sums.insert(grid[row][col]);

                for (int k = 1; ; ++k) {
                    if (row - k < 0 || row + k >= rows ||
                        col - k < 0 || col + k >= cols) {
                        break;
                    }

                    int sum = 0;
                    // top to right 
                    for (int i = 0; i < k; ++i) {
                        sum += grid[row - k + i][col + i];
                    }
                    // right to bottom 
                    for (int i = 0; i < k; ++i) {
                        sum += grid[row + i][col + k - i];
                    }
                    // bottom to left
                    for (int i = 0; i < k; ++i) {
                        sum += grid[row + k - i][col - i];
                    }
                    // left to top
                    for (int i = 0; i < k; ++i) {
                        sum += grid[row - i][col - k + i];
                    }

                    sums.insert(sum);
                }
            }
        }

        vector<int> result;
        for (int sum : sums) {
            result.push_back(sum);
            if (result.size() == 3) break;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {3,4,5,1,3},
        {3,3,4,2,3},
        {20,30,200,40,10},
        {1,5,5,4,1},
        {4,3,2,2,5}
    };
    vector<int> result = solution.getBiggestThree(grid); //  [228,216,211]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}