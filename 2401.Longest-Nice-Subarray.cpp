#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const int n = nums.size();
        int result = 0;
        int left = 0;
        int current = 0;
        for (int right = 0; right < n; ++right) {
            while (current & nums[right]) {
                current = current ^ nums[left++];
            }
            result = max(result, right - left + 1);
            current = current | nums[right];
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,3,8,48,10};
    cout << solution.longestNiceSubarray(nums) << endl; // 3
}