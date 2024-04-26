#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> dp = grid[0];
        pair<int, int> minIndices = getMinTwoIndices(dp);
        for (int row = 1; row < n; ++row) {
            vector<int> next_dp;
            for (int col = 0; col < n; ++col) {
                int currentValue = grid[row][col];
                int minValue = INT_MAX;
                for (int prevIndex : {minIndices.first, minIndices.second}) {
                    if (col != prevIndex) {
                        minValue = min(minValue, currentValue + dp[prevIndex]);
                    }
                }
                next_dp.push_back(minValue);
            }
            dp = next_dp;
            minIndices = getMinTwoIndices(dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
private:
    pair<int, int> getMinTwoIndices(vector<int>& row) {
        int min = 0;
        int secondMin = 0;
        for (int i = 1; i < row.size(); ++i) {
            if (row[min] > row[i]) {
                secondMin = min;
                min = i;
            } else if (row[secondMin] > row[i]) {
                secondMin = i;
            }
        }
        return {min, secondMin};
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << solution.minFallingPathSum(grid) << endl; // 13
}