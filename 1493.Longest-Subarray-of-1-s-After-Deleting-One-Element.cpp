#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int zeroCount = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zeroCount;
            while (zeroCount > 1) {
                if (nums[left++] == 0) --zeroCount;
            }
            result = max(result, right - left);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    cout << solution.longestSubarray(nums) << endl; // 5
}