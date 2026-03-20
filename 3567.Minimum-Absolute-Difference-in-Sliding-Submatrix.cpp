#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> result(rows - k + 1, vector<int>(cols - k + 1));
        for (int row = 0; row <= rows - k; ++row) {
            for (int col = 0; col <= cols - k; ++col) {
                vector<int> values;
                for (int i = row; i < row + k; ++i) {
                    for (int j = col; j < col + k; ++j) {
                        values.push_back(grid[i][j]);
                    }
                }
                sort(values.begin(), values.end());
                int minDiff = INT_MAX;
                for (int i = 1; i < values.size(); ++i) { 
                    if (values[i - 1] == values[i]) continue;
                    minDiff = min(minDiff, abs(values[i] - values[i - 1]));
                }
                if (minDiff != INT_MAX) {
                    result[row][col] = minDiff;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,-2,3},
        {2,3,5}
    };
    vector<vector<int>> result = solution.minAbsDiff(grid, 2); // [[1,2]]
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