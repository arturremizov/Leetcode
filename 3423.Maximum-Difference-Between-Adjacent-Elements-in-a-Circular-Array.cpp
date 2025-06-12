#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = abs(nums.back() - nums.front());
        for (int i = 1; i < nums.size(); ++i) {
            result = max(result, abs(nums[i - 1] - nums[i]));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,4};
    cout << solution.maxAdjacentDistance(nums) << endl; // 3
}