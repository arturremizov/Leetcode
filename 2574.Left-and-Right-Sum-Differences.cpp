#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n);
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] + nums[i - 1];
        }
        int rightSum = 0;
        for (int i = n - 2; i >= 0; --i) {
            rightSum += nums[i + 1];
            result[i] = abs(result[i] - rightSum);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {10,4,8,3};
    vector<int> result = solution.leftRightDifference(nums); // [15,1,11,22]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}