#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int n = nums.size();
        const int pairs = n / 2;

        vector<int> diff(2 * limit + 2);
        for (int i = 0; i < pairs; ++i) {
            int num1 = nums[i];
            int num2 = nums[n - i - 1];

            int minSum = min(num1, num2) + 1;
            int maxSum = max(num1, num2) + limit;

            diff[minSum] -= 1;
            diff[maxSum + 1] += 1;

            diff[num1 + num2] -= 1;
            diff[num1 + num2 + 1] += 1;
        }

        int result = INT_MAX;
        int current = 0;
        int base = pairs * 2;
        for (int sum = 2; sum <= 2 * limit; ++sum) {
            current += diff[sum];
            result = min(result, base + current);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,4,3};
    cout << solution.minMoves(nums, 4) << endl; // 1
}
