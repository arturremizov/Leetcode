#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int maxValue = 0;
                for (int row = i; row < i + 3; ++row) {
                    for (int col = j; col < j + 3; ++col) {
                        maxValue = max(maxValue, grid[row][col]);                                      
                    }
                }
                result[i][j] = maxValue;
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {9,9,8,1},
        {5,6,2,6},
        {8,2,6,4},
        {6,2,2,2}
    };
    vector<vector<int>> result = solution.largestLocal(grid); // [[9,9],[8,6]]
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