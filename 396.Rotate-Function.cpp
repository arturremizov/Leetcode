#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int n = nums.size();
        int sum = 0;
        int curF = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            curF += nums[i] * i;
        }

        int result = curF;
        for (int k = 1; k < n; ++k) {
            int movedNum = nums[n - k];
            curF = curF + sum - movedNum * n;
            result = max(result, curF);
        }
        return result;
    }
};

int main() {
    Solution solution;  
    vector<int> nums = {4,3,2,6};
    cout << solution.maxRotateFunction(nums) << endl; // 26
}