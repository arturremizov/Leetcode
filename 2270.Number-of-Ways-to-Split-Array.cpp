#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int n = nums.size();
        int64_t right = accumulate(nums.begin(), nums.end(), (int64_t)0);
        int64_t left = 0;
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {10,4,-8,7};
    cout << solution.waysToSplitArray(nums) << endl; // 2
}