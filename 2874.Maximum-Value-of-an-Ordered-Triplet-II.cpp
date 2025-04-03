#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        long long maxNum = nums[0];
        long long maxDifference = 0;
        for (int k = 2; k < nums.size(); ++k) {
            if (nums[k - 2] > maxNum) {
                maxNum = nums[k - 2];
            }
            maxDifference = max(maxDifference, maxNum - nums[k - 1]);
            result = max(result, maxDifference * nums[k]);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {15,12,2,14,15,18,15,20};
    cout << solution.maximumTripletValue(nums) << endl; // 260
}