#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> numToIndexMap;
        for (int i = 0; i < nums.size(); ++i) {
            numToIndexMap[nums[i]] = i;
        }

        unordered_map<int, int> memo;
        int result = -1;
        for (int i = 0; i < nums.size(); ++i) {
            result = max(result, helper(nums, i, numToIndexMap, memo));
        }
        return result >= 2 ? result : -1;
    }
private:
    int helper(vector<int>& nums, int i, unordered_map<int, int>& numToIndexMap, unordered_map<int, int>& memo) {
        int num = nums[i];
        if (memo.count(num)) return memo[num];
        long long square = (long long)num * num;
        int result = 1;
        if (square < 100001 && numToIndexMap.count(square)) {
            result += helper(nums, numToIndexMap[square], numToIndexMap, memo);
        }
        memo[num] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,3,6,16,8,2};
    cout << solution.longestSquareStreak(nums) << endl; // 3
}