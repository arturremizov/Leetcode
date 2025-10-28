#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int rightSum = 0;
        for (int num : nums) rightSum += num;

        int leftSum = 0;
        int result = 0;
        for (int num : nums) {
            if (num != 0) {
                leftSum += num;
                rightSum -= num;
            } else {
                bool canGoLeft = leftSum - rightSum >= 0;
                if (canGoLeft && leftSum - rightSum <= 1) {
                    ++result;
                }
                bool canGoRight = rightSum - leftSum >= 0;
                if (canGoRight && rightSum - leftSum <= 1) {
                    ++result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,0,2,0,3};
    cout << solution.countValidSelections(nums) << endl; // 2
}