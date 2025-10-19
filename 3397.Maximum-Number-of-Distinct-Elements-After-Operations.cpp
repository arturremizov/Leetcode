#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int prevNum = INT_MIN;
        for (int num : nums) {
            int curNum = max(num - k, prevNum + 1);
            if (curNum <= num + k) {
                ++result;
                prevNum = curNum;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,2,3,3,4};
    cout << solution.maxDistinctElements(nums,2) << endl; // 6
}