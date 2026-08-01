#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> memo = vector(n, vector<int>(n, INT_MIN));
        int difference = dfs(0, n - 1, nums, memo);
        return difference >= 0;
    }
private:
    int dfs(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (left == right) return nums[left];
        if (memo[left][right] != INT_MIN) return memo[left][right];
        int takeLeft = nums[left] - dfs(left + 1, right, nums, memo);
        int takeRight = nums[right] - dfs(left, right - 1, nums, memo);
        return memo[left][right] = max(takeLeft, takeRight);
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,5,233,7};
    cout << solution.predictTheWinner(nums) << endl; // true
}