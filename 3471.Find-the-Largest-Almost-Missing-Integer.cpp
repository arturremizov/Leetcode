#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k == n) return *max_element(nums.begin(), nums.end());
        
        vector<int> freq(51);
        for (int num : nums) freq[num]++;

        if (k == 1) {
            int result = -1;
            for (int num = 0; num <= 50; ++num) {
                if (freq[num] == 1) {
                    result = max(result, num);
                }
            }
            return result;
        }

        int firstNum = nums[0], lastNum = nums[n - 1];
        int result = freq[firstNum] == 1 ? firstNum : -1;
        if (freq[lastNum] == 1) {
            result = max(result, lastNum);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,9,2,1,7};
    cout << solution.largestInteger(nums, 3) << endl; // 7
}