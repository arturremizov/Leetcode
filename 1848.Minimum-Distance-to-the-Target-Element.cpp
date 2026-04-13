#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int n = nums.size();
        int result = n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                result = min(result, abs(i - start));
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4,5};
    cout << solution.getMinDistance(nums, 5, 3) << endl; // 1
}