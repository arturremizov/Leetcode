#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> prefix(k, LONG_LONG_MAX);
        prefix[0] = 0;
        long long result = LONG_LONG_MIN;
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += nums[i];
            int length = i + 1;
            int prefixLength = length % k;
            if (prefix[prefixLength] != LONG_LONG_MAX) {
                result = max(result, total - prefix[prefixLength]);
            }
            prefix[prefixLength] = min(prefix[prefixLength], total);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {-5,1,2,-3,4};
    cout << solution.maxSubarraySum(nums, 2) << endl; // 4
}