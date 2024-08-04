#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subArraySums;
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                subArraySums.push_back(currentSum);
            }
        }

        sort(subArraySums.begin(), subArraySums.end());

        const int MOD = pow(10, 9) + 7;
        int result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + subArraySums[i]) % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4};
    cout << solution.rangeSum(nums, 4, 1, 5) << endl; // 13
}