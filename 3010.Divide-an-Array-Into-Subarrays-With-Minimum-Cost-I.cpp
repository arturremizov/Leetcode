#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const int n = nums.size();
        int num2 = 51, num3 = 51;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < num3) {
                num2 = num3;
                num3 = nums[i];
            } else if (nums[i] < num2) {
                num2 = nums[i];
            }
        }
        return nums[0] + num2 + num3;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {10,3,1,1};
    cout << solution.minimumCost(nums) << endl; // 12
}