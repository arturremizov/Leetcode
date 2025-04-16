#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        const int n = nums.size();
        int left = 0;
        long long result = 0;
        unordered_map<int, int> numsCount;
        int pairsCount = 0;
        for (int right = 0; right < n; ++right) {
            pairsCount += numsCount[nums[right]];
            numsCount[nums[right]]++;

            while (pairsCount >= k) {
                result += n - right;
                numsCount[nums[left]]--;
                pairsCount -= numsCount[nums[left]];
                ++left;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,1,4,3,2,2,4};
    cout << solution.countGood(nums, 2) << endl; // 4
}