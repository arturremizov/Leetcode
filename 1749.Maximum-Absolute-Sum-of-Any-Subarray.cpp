#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentSum = 0;
        int minPrefSum = 0, maxPrefSum = 0;
        int result = 0;
        for (int num : nums) {
            currentSum += num;
            result = max(result,
                max(abs(currentSum - minPrefSum), abs(currentSum - maxPrefSum))
            );
            minPrefSum = min(minPrefSum, currentSum);
            maxPrefSum = max(maxPrefSum, currentSum);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,-3,2,3,-4};
    cout << solution.maxAbsoluteSum(nums) << endl; // 5
}