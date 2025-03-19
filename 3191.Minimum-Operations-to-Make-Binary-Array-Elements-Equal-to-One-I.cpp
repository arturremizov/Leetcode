#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int result = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                flip(nums, i);
                flip(nums, i + 1);
                flip(nums, i + 2);
                ++result;
            }
        }
        if (nums[n - 1] == 0 || nums[n - 2] == 0) {
            return -1;
        }
        return result;
    }
private:
    void flip(vector<int>& nums, int i) {
        nums[i] = nums[i] == 1 ? 0 : 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,1,1,0,0};
    cout << solution.minOperations(nums) << endl; // 3
}