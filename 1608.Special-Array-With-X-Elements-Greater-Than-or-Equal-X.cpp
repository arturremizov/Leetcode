#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> count(n + 1);
        for (int num : nums) {
            int index = num < n ? num : n;
            count[index]++;
        }
        int totalRight = 0;
        for (int i = n; i > 0; --i) {
            totalRight += count[i];
            if (i == totalRight) {
                return i;
            }
        }
        return -1;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {3,5};
    cout << solution.specialArray(nums1) << endl; // 2
    vector<int> nums2 = {0,0};
    cout << solution.specialArray(nums2) << endl; // -1
    vector<int> nums3 = {0,4,3,0,4};
    cout << solution.specialArray(nums3) << endl; // 3
}