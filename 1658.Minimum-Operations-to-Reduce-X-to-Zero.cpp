#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int result = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (left <= right && sum > target) {
                sum -= nums[left];
                ++left;
            }
            if (sum == target) {
                result = min(result, n - (right - left + 1));
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,1,4,2,3};
    cout << solution.minOperations(nums, 5) << endl; // 2
}