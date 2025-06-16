#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1;
        int curMin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= curMin) {
                curMin = nums[i];
            } else {
                result = max(result, nums[i] - curMin);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {7,1,5,4};
    cout << solution.maximumDifference(nums) << endl; // 4
}