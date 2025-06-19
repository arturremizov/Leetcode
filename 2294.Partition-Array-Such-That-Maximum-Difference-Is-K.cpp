#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 1;
        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[j] > k) {
                ++result;
                j = i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,6,1,2,5};
    cout << solution.partitionArray(nums,2) << endl; // 2
}