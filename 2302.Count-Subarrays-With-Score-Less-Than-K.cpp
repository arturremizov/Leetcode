#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result = 0;
        int left = 0;
        long long currSum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            currSum += nums[right];
            while (currSum * (right - left + 1) >= k) {
                currSum -= nums[left++];
            }
            result += right - left + 1;
        }
        return result; 
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,1,4,3,5};
    cout << solution.countSubarrays(nums, 10) << endl; // 6
}
