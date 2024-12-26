#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> nextDp;
            for (auto [currentSum, count] : dp) {
                nextDp[currentSum + nums[i]] += count;
                nextDp[currentSum - nums[i]] += count;
            }           
            dp = nextDp;
        }
        return dp[target];        
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,1,1,1,1};
    cout << solution.findTargetSumWays(nums, 3) << endl; // 5
}