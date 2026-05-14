#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        if (nums[n] != n || nums[n - 1] != n) return false;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != i + 1) return false;
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1, 3, 3, 2};
    cout << solution.isGood(nums) << endl; // true
}
