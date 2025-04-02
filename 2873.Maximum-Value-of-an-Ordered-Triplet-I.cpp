#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();
        long long result = 0;
        int left = nums[0];
        for (int j = 1; j < n; ++j) {
            if (left < nums[j]) {
                left = nums[j];
                continue;
            }
            for (int k = j + 1; k < n; ++k) {
                result = max(result, (long long)(left - nums[j]) * nums[k]);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {12,6,1,2,7};
    cout << solution.maximumTripletValue(nums) << endl; // 77
}