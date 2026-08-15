#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorTotal = 0;
        bool isAllZero = true;
        for (int num : nums) {
            xorTotal ^= num;
            if (num > 0) isAllZero = false;
        }
        if (xorTotal != 0) return nums.size();
        return isAllZero ? 0 : nums.size() - 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    cout << solution.longestSubsequence(nums) << endl; // 2
}