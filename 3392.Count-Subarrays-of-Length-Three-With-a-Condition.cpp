#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] / 2.0 == nums[i - 1] + nums[i + 1]) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,1,4,1};
    cout << solution.countSubarrays(nums) << endl; // 1
}
