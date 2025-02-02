#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] % 2 == nums[i] % 2) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,1,4};
    cout << solution.isArraySpecial(nums) << endl; // true
}