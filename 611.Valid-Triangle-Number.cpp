#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = n - 1; i >= 0; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    result += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,2,3,4};
    cout << solution.triangleNumber(nums) << endl; // 3
}