#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        int minNum = INT_MAX, maxNum = INT_MIN;
        int minNumI = 0, maxNumI = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minNum) {
                minNum = nums[i];
                minNumI = i;
            } 
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxNumI = i;
            }
        }
        int left = min(minNumI, maxNumI);
        int right = max(minNumI, maxNumI);
        return min({right + 1, left + 1 + n - right, n - left});
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,10,7,5,4,1,8,6};
    cout << solution.minimumDeletions(nums) << endl; // 5
}