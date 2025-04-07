#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        const int target = sum / 2;
        unordered_set<int> dp = {0};
        for (int i = n - 1; i >= 0; --i) {
            unordered_set<int> nextDp = dp;
            for (int num : dp) {
                int current = num + nums[i];
                if (current == target) return true;
                if (current > target) continue;
                nextDp.insert(current);
            }
            dp = nextDp;
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,5,11,5};
    cout << solution.canPartition(nums) << endl; // true
}