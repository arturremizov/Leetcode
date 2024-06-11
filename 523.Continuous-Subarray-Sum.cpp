#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> reminderMap; // reminder : index
        reminderMap[0] = -1;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int reminder = currentSum % k;
            if (reminderMap.count(reminder)) {
                if (i - reminderMap[reminder] >= 2) {
                    return true;
                }             
            } else {
                reminderMap[reminder] = i;
            }
        }
        return false;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {23,2,4,6,7};
    cout << solution.checkSubarraySum(nums1, 6) << endl; // true
    vector<int> nums2 = {23,2,6,4,7};
    cout << solution.checkSubarraySum(nums2, 7) << endl; // true
}