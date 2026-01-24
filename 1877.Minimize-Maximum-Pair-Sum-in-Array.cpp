#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        int result = 0;
        while (left < right) {
            result = max(result, nums[left] + nums[right]);
            ++left, --right;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,1,5,1,2,5,1,5,5,4};
    cout << solution.minPairSum(nums) << endl; // 8
}