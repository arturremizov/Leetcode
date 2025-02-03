#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing = 1, decreasing = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                decreasing = 1;
                result = max(result, ++increasing);
            } else if (nums[i - 1] > nums[i]) {
                increasing = 1;
                result = max(result, ++decreasing);
            } else {
                decreasing = 1;
                increasing = 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,4,3,3,2};
    cout << solution.longestMonotonicSubarray(nums) << endl; // 2
}