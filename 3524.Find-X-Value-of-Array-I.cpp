#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k));
        for (int i = 0; i < n; ++i) {
            int reminder = nums[i] % k;
            dp[i][reminder]++;
            if (i == 0) continue;
            for (int prevReminder = 0; prevReminder < k; ++prevReminder) {
                dp[i][(reminder * prevReminder) % k] += dp[i - 1][prevReminder];
            }
        }
        vector<long long> result(k);
        for (int i = 0; i < n; ++i) {
            for (int reminder = 0; reminder < k; ++reminder) {
                result[reminder] += dp[i][reminder];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4,5};
    vector<long long> result = solution.resultArray(nums, 3); // [9,2,4]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}