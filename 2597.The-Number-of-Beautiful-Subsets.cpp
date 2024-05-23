#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        return helper(nums, k, 0, count) - 1;
    }
private: 
    int helper(vector<int>& nums, int k, int i, unordered_map<int, int>& count) {
        if (i == nums.size()) return 1;
        int result = helper(nums, k, i + 1, count); // skip nums[i]
        if (!count[nums[i] - k] && !count[nums[i] + k]) {
            count[nums[i]]++;
            result += helper(nums, k, i + 1, count); // include nums[i]
            count[nums[i]]--;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {2,4,6};
    cout << solution.beautifulSubsets(nums, 2) << endl; // 4
    vector<int> nums2 = {1};
    cout << solution.beautifulSubsets(nums2, 1) << endl; // 1
}