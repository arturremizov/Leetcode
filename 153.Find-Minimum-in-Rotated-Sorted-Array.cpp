#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }
            int mid = (right + left) / 2;
            result = min(result, nums[mid]);
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,4,5,1,2};
    cout << solution.findMin(nums) << endl; // 1
}
