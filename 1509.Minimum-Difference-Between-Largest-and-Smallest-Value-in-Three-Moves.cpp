#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 4) return 0;

        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for (int left = 0; left < 4; ++left) {
            int right = n - 4 + left;
            result = min(result, nums[right] - nums[left]);
        }
        return result;        
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {5,3,2,4};
    cout << solution.minDifference(nums) << endl; // 0
    vector<int> nums2 = {1,5,0,10,14};
    cout << solution.minDifference(nums2) << endl; // 1
    vector<int> nums3 = {3,100,20};
    cout << solution.minDifference(nums3) << endl; // 0
}