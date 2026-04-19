#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        int result = 0;
        int left = 0;
        for (int right = 0; right < m; ++right) {
            while (left < n && left <= right && nums1[left] > nums2[right]) {
                ++left;
            }
            if (left < n && left <= right) {
                result = max(result, right - left);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};
    cout << solution.maxDistance(nums1, nums2) << endl; // 2
}