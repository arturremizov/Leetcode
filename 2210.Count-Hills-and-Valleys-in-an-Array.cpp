#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i - 1];
                continue;
            }
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1] || 
                nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,4,1,1,6,5};
    cout << solution.countHillValley(nums) << endl; // 3
}