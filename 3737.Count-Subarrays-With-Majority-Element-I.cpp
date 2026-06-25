#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) ++count;
                int length = j - i + 1;
                if (count > length / 2) {
                    ++result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,2,3};
    cout << solution.countMajoritySubarrays(nums, 2) << endl; // 5
}