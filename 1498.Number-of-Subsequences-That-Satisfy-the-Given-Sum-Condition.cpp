#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9+7, n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> powers(n,1);
        for (int i = 1; i < n; ++i) {
            powers[i] = (powers[i - 1] * 2 % MOD);
        }

        int right = n - 1;
        int result = 0;
        for (int left = 0; left < n; ++left) {
            while (left <= right && nums[left] + nums[right] > target) {
                --right;
            }
            if (left <= right) {
                result = (result + powers[right - left]) % MOD;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,5,6,7};
    cout << solution.numSubseq(nums, 9) << endl; // 4
}