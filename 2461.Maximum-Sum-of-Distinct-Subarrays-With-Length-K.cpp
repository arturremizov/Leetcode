#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        long long result = 0;
        long long currentSum = 0;
        unordered_map<int, int> numsCount;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            numsCount[nums[right]]++;
            if (right - left + 1 > k) {
                int leftNum = nums[left];
                currentSum -= leftNum;
                numsCount[leftNum]--;
                if (numsCount[leftNum] == 0) {
                    numsCount.erase(leftNum);
                }
                ++left;
            }
            if (right - left + 1 == k && numsCount.size() == k) {
                result = max(result, currentSum);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,5,4,2,9,9,9};
    cout << solution.maximumSubarraySum(nums, 3) << endl; // 15
}