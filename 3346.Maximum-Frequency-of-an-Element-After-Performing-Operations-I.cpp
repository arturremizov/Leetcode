#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> numCount;
        for (int num : nums) {
            numCount[num]++;
        }

        sort(nums.begin(), nums.end());

        int result = 0;
        for (int num = nums.front(); num <= nums.back(); ++num) {
            int left = binarySearchLeft(num - k, nums);
            int right = binarySearchRight(num + k, nums);
            
            int possibleGroup = right - left + 1;
            int currFreq = min(possibleGroup, numCount[num] + numOperations);
            result = max(result, currFreq);
        }
        return result;
    }
private:
    int binarySearchLeft(int target, vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    int binarySearchRight(int target, vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
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
    vector<int> nums = {1,4,5};
    cout << solution.maxFrequency(nums,1,2) << endl; // 2
}