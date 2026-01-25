#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for (int i = 0; i < n - k + 1; ++i) {
            int difference = nums[i + k - 1] - nums[i];
            result = min(result, difference);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {9,4,1,7};
    cout << solution.minimumDifference(nums, 2) << endl; // 2
}