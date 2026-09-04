#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> prefMin(n);
        prefMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            prefMin[i] = min(prefMin[i + 1], nums[i]);
        }
        int curMax = 0;
        for (int i = 0; i < n; ++i) {
            curMax = max(curMax, nums[i]);
            if (curMax - prefMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {5,0,1,4};
    cout << solution.firstStableIndex(nums, 3) << endl; // 3
}