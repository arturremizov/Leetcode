#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int n = nums.size();
        vector<int> maxRight(n);
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                maxRight[i] = nums[i];
            } else {
                maxRight[i] = max(maxRight[i + 1], nums[i]);
            }
        }
        int result = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (nums[left] > maxRight[right]) {
                ++left;
            }
            result = max(result, right - left);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {6,0,8,2,1,5};
    cout << solution.maxWidthRamp(nums) << endl; // 4
}