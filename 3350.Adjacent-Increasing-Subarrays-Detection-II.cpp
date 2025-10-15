#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        const int n = nums.size();
        int increasing = 1, prevIncreasing = 0;
        int result = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++increasing;
            } else {
                prevIncreasing = increasing;
                increasing = 1;
            }

            result = max({
                result,
                min(increasing, prevIncreasing),
                max(increasing, prevIncreasing) / 2
            });
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    cout << solution.maxIncreasingSubarrays(nums) << endl; // 3
}