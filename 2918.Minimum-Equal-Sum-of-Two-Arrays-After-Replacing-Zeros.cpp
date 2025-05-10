#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long nums1Sum = 0, nums2Sum = 0;
        int nums1ZeroCount = 0, nums2ZeroCount = 0;
        for (int num : nums1) {
            nums1Sum += num;
            if (num == 0) {
                ++nums1ZeroCount;
                ++nums1Sum;
            }
        }
        for (int num : nums2) {
            nums2Sum += num;
            if (num == 0) {
                ++nums2ZeroCount;
                ++nums2Sum;
            } 
        }
        if ((nums1ZeroCount == 0 && nums2Sum > nums1Sum) ||
             nums2ZeroCount == 0 && nums1Sum > nums2Sum) {
            return -1;
        }

        return max(nums1Sum, nums2Sum);
    }
};

int main() {
    Solution solution; 
    vector<int> nums1 = {3,2,0,1,0};
    vector<int> nums2 = {6,5,0};
    cout << solution.minSum(nums1,nums2) << endl; // 12
}
 