#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        int result = INT32_MAX;
        long currentSum = 0;
        deque<pair<long, int>> deque;
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            if (currentSum >= k) {
                result = min(result, right + 1);
            }
            while (!deque.empty() && currentSum - deque.front().first >= k) {
                auto [prefix, endIndex] = deque.front();
                deque.pop_front();
                result = min(result, right - endIndex);
            }
            while (!deque.empty() && deque.back().first > currentSum) {
                deque.pop_back();
            }
            deque.push_back({currentSum, right});
        }
        return result == INT32_MAX ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,-1,2};
    cout << solution.shortestSubarray(nums, 3) << endl; // 3
}