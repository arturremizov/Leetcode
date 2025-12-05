#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        const int n = nums.size();
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[0];
            rightSum -= nums[0];
            if ((leftSum - rightSum) % 2 == 0) {
                ++result;
            }
        }
        return result;
    }   
};

int main() {
    Solution solution; 
    vector<int> nums = {10,10,3,7,6};
    cout << solution.countPartitions(nums) << endl; // 4
}