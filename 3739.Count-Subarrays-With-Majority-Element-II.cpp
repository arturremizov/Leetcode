#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<int> prefixSumFreq(n * 2 + 1); // values [-n 0 n]
        int curPrefixSum = n; // offset = n;
        prefixSumFreq[curPrefixSum] = 1; // empty array
        long long prefSumLessThanCurCount = 0;
        long long result = 0;
        for (int num : nums) {
            if (num == target) {
                prefSumLessThanCurCount += prefixSumFreq[curPrefixSum];
                curPrefixSum++;
                prefixSumFreq[curPrefixSum]++;
            } else {
                curPrefixSum--;
                prefSumLessThanCurCount -= prefixSumFreq[curPrefixSum];
                prefixSumFreq[curPrefixSum]++;
            }
            result += prefSumLessThanCurCount;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,2,3};
    cout << solution.countMajoritySubarrays(nums, 2) << endl; // 5
}