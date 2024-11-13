#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0; i < n; i++) {
            int low = lower - nums[i];
            int up = upper - nums[i];

            result += (
                binarySearch(nums, i + 1, n - 1, up + 1) - 
                binarySearch(nums, i + 1, n - 1, low)
            );
        }
        return result;
    }
private:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;        
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {0,1,7,4,4,5};
    cout << solution.countFairPairs(nums, 3, 6) << endl; // 6
}
