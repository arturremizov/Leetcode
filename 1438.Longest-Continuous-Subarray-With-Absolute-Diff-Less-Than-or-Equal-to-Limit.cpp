#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> min_deque, max_deque;
        int left = 0;
        int result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            const int num = nums[right];
            while (!min_deque.empty() && num < min_deque.back()) {
                min_deque.pop_back();
            }
            while (!max_deque.empty() && num > max_deque.back()) {
                max_deque.pop_back();
            }
            min_deque.push_back(num);
            max_deque.push_back(num);
            
            while (max_deque.front() - min_deque.front() > limit) {
                if (nums[left] == max_deque.front()) {
                    max_deque.pop_front();
                } 
                if (nums[left] == min_deque.front()) {
                    min_deque.pop_front();
                }
                ++left;
            }

            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {8,2,4,7};
    cout << solution.longestSubarray(nums1, 4) << endl; // 2
    vector<int> nums2 = {10,1,2,4,7,2};
    cout << solution.longestSubarray(nums2, 5) << endl; // 4
}