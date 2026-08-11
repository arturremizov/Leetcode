#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const int n = nums.size();
        int prefSum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] + 1 != nums[i]) break;
            prefSum += nums[i];
        }
        unordered_set<int> numsSet(nums.begin(), nums.end());
        while (numsSet.count(prefSum)) {
            ++prefSum;
        }
        return prefSum;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,4,5,1,12,14,13};
    cout << solution.missingInteger(nums) << endl; // 15
}