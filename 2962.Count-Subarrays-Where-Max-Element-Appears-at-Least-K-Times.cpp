#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        const int maxNum = *max_element(nums.begin(), nums.end());
        int left = 0;
        int maxNumCount = 0;
        long long result = 0;
        for (int right = 0; right < n; ++right) {
            maxNumCount += nums[right] == maxNum;
            while (maxNumCount >= k) {
                result += n - right;
                maxNumCount -= nums[left++] == maxNum;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,2,3,3};
    cout << solution.countSubarrays(nums, 2) << endl; // 6
}
 