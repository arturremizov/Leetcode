#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] < k) return -1;
        int result = 0;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] != nums[i - 1]) {
                ++result;
            }
            if (nums[i] == k) return result;
        }
        if (nums[0] != k) {
            ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {5,2,5,4,5};
    cout << solution.minOperations(nums, 2) << endl; // 2
}