#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int result = 0;
        const int n = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n + max; ++i) {
            if (count[i] > 1) {
                int extra = count[i] - 1;
                result += extra;
                count[i + 1] += extra;
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {1,2,2};
    cout << solution.minIncrementForUnique(nums1) << endl; // 1
    vector<int> nums2 = {3,2,1,2,1,7};
    cout << solution.minIncrementForUnique(nums2) << endl; // 6
}