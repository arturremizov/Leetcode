#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        vector<long long> candidates;
        for (int num : nums) {
            candidates.push_back(num);
            candidates.push_back(num - k);
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());


        int result = 0;
        for (long long candidate : candidates) {
            int leftMin = binarySearchLeft(candidate - k, nums);
            int rightMax = binarySearchRight(candidate + k, nums);
            int possibleGroup = rightMax - leftMin + 1;

            int left = binarySearchLeft(candidate, nums);
            int right = binarySearchRight(candidate, nums);
            int currentGroup = right - left + 1;

            int needOperationCount = possibleGroup - currentGroup;
            int canChange = min(needOperationCount, numOperations);

            int currentFreq = currentGroup + canChange;
            result = max(result, currentFreq);
        }
        return result;
    }
private:
    int binarySearchLeft(long long target, vector<int>& nums) {
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
    int binarySearchRight(long long target, vector<int>& nums) {
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