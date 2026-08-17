#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, n - 1, sum, stoneValue, memo);
    }
private:
    int dfs(int left, int right, int sum, vector<int>& stoneValue, vector<vector<int>>& memo) {
        if (left == right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        int leftSum = 0;
        int result = 0;
        for (int i = left; i < right; ++i) {
            leftSum += stoneValue[i];
            int rightSum = sum - leftSum;
            if (leftSum < rightSum) {
                result = max(result, leftSum + dfs(left, i, leftSum, stoneValue, memo));
            } else if (leftSum > rightSum) {
                result = max(result, rightSum + dfs(i + 1, right, rightSum, stoneValue, memo));
            } else {
                result = max(
                    result, 
                    leftSum + max(dfs(left, i, leftSum, stoneValue, memo), dfs(i + 1, right, rightSum, stoneValue, memo))
                );
            }
        }
        return memo[left][right] = result;
    }
};

int main() {
    Solution solution;
    vector<int> stoneValue = {6,2,3,4,5,5};
    cout << solution.stoneGameV(stoneValue) << endl; // 18
}