#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int const n = nums.size();
        int totalOnes = 0;
        for (int num : nums) {
            if (num == 1) ++totalOnes;
        }

        int left = 0;
        int widowsOnes = 0;
        int maxWindowOnes = 0;
        for (int right = 0; right < n * 2; ++right) {
            if (nums[right % n]) {
                ++widowsOnes;
            } 
            if (right - left + 1 > totalOnes) {
                widowsOnes -= nums[left % n];
                ++left;
            }

            maxWindowOnes = max(maxWindowOnes, widowsOnes); 
        }
        return totalOnes - maxWindowOnes;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,1,1,0,0,1,1,0};
    cout << solution.minSwaps(nums) << endl; // 2
}