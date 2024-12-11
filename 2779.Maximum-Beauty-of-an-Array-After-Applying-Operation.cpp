#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > 2 * k) {
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,6,1,2};
    cout << solution.maximumBeauty(nums, 2) << endl; // 3
}