#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (int num : nums) {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        return (maxNum - minNum) * 1LL * k;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,2,5,1};
    cout << solution.maxTotalValue(nums, 3) << endl; // 12
}