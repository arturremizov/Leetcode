#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = n;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (1LL * nums[left] * k < nums[right]) {
                ++left;
            }
            result = min(result, n - (right - left + 1));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,6,2,9};
    cout << solution.minRemoval(nums, 3) << endl; // 2
}