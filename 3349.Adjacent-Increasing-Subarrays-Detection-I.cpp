#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        int prevIncreasing = 0;
        int increasing = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++increasing;
            } else {
                prevIncreasing = increasing;
                increasing = 1;
            }
            if ((prevIncreasing >= k && increasing >= k) || 
                 max(increasing, prevIncreasing) / k >= 2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {-15,19};
    cout << solution.hasIncreasingSubarrays(nums, 1) << endl; // true
}