#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return true;
        int windowCount = 1;
        for (int i = 1; i < n * 2; ++i) {
            if (nums[(i - 1) % n] <= nums[i % n]) {
                ++windowCount; 
            } else {
                windowCount = 1;
            }
            if (windowCount == n) return true;
        }
        return false;   
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,4,5,1,2};
    cout << solution.check(nums) << endl; // true
}