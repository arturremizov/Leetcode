#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int maxNum = *max_element(nums.begin(), nums.end());
        // int size = 0;
        // int result = 0;
        // for (int num : nums) {
        //     if (num == maxNum) {
        //         ++size;
        //     } else {
        //         size = 0;
        //     }
        //     result = max(result, size);
        // }

        int size = 0;
        int currentMax = 0;
        int result = 0;
        for (int num : nums) {
            if (num > currentMax) {
                currentMax = num;
                size = 1;
                result = 0;
            } else if (num == currentMax) {
                ++size;
            } else {
                size = 0;
            }
            result = max(result, size);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {1,2,3,3,2,2};
    cout << solution.longestSubarray(nums) << endl; // 2
}