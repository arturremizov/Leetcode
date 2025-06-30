#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (left < right && nums[right] - nums[left] > 1) {
                ++left;
            }
            if (nums[right] - nums[left] == 1) {
                result = max(result, right - left + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << solution.findLHS(nums) << endl; // 5
}