#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> memo(nums.size(), -2);
        return dfs(0, nums, target, memo);
    }
private:
    int dfs(int i, vector<int>& nums, int target, vector<int>& memo) {
        const int n = nums.size();
        if (i == n - 1) return 0;
        if (memo[i] != -2) return memo[i];
        int result = -1;
        for (int j = i + 1; j < n; ++j) {
            int diff = nums[j] - nums[i];
            if (-target <= diff && diff <= target) {
                int next = dfs(j, nums, target, memo);
                if (next != -1) {
                    result = max(result, 1 + next);
                }
            }
        }
        return memo[i] = result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,6,4,1,2};
    cout << solution.maximumJumps(nums, 2) << endl; // 3
}