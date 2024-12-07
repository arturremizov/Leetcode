#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private: 
    bool canDivide(vector<int>& nums, int maxOperations, int maxBalls) {
        int operations = 0;
        for (int num : nums) {
            operations += ceil((double)num / maxBalls) - 1;
            if (operations > maxOperations) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,4,8,2};
    cout << solution.minimumSize(nums,4) << endl; // 2
}