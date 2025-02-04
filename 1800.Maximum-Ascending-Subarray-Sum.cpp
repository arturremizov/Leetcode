#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }
            result = max(result, currentSum);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {10,20,30,5,10,50};
    cout << solution.maxAscendingSum(nums) << endl; // 65
}