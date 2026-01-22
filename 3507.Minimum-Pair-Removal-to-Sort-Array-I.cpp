#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int result = 0;
        while (nums.size() > 1) {
            bool isAscending = true;
            int minSum = INT_MAX;
            int index = 0;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    isAscending = false;
                }
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }
            if (isAscending) break;
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);
            ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {5,2,3,1};
    cout << solution.minimumPairRemoval(nums) << endl; // 2
}