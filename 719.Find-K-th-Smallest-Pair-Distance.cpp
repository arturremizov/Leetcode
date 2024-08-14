#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + ((right - left) / 2);
            int pairs = countPairs(nums, mid);
            if (pairs >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    int countPairs(vector<int>& nums, int dist) {
        int left = 0;
        int result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > dist) {
                ++left;
            }
            result += right - left;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {1,3,1};
    cout << solution.smallestDistancePair(nums1, 1) << endl; // 0
    vector<int> nums2 = {1,6,1};
    cout << solution.smallestDistancePair(nums2, 3) << endl; // 5
}