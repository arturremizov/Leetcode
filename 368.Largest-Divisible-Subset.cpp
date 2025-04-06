#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = {nums[i]};
        }

        vector<int> result;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0) {
                    vector<int> temp = {nums[i]};
                    temp.insert(temp.end(), dp[j].begin(), dp[j].end());
                    if (temp.size() > dp[i].size()) {
                        dp[i] = temp;
                    }
                }
            }
            if (dp[i].size() > result.size()) {
                result = dp[i];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,4,8};
    vector<int> result = solution.largestDivisibleSubset(nums); //[1,2,4,8]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}