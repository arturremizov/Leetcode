#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int cols = grid[0].size();

        vector<long long> prefixSumRow1(cols, 0);
        vector<long long> prefixSumRow2(cols, 0);

        prefixSumRow1[0] = grid[0][0];
        prefixSumRow2[0] = grid[1][0];

        for (int i = 1; i < cols; ++i) {
            prefixSumRow1[i] = prefixSumRow1[i - 1] + grid[0][i];
            prefixSumRow2[i] = prefixSumRow2[i - 1] + grid[1][i];
        }

        long long result = LLONG_MAX;
        for (int i = 0; i < cols; ++i) {
            long long topSum = prefixSumRow1[cols - 1] - prefixSumRow1[i];
            long long bottomSum = i == 0 ? 0 : prefixSumRow2[i - 1];
            long long secondRobotSum = max(topSum, bottomSum);
            result = min(result, secondRobotSum);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {2,5,4},
        {1,5,1}
    }; 
    cout << solution.gridGame(grid) << endl; // 4
}