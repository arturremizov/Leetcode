#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int n = nums.size();
        vector<int> deltas(n);
        for (int i = 0; i < n; ++i) {
            deltas[i] = (nums[i] ^ k) - nums[i];
        }
        sort(deltas.begin(), deltas.end(), greater<int>());
        long long result = 0;
        for (int num : nums) {
            result += num;
        }
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1) break;
            int delta = deltas[i] + deltas[i+1];
            if (delta <= 0) break;
            result += delta;            
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {1,2,1};
    vector<vector<int>> edges = {{0,1}, {0,2}};
    cout << solution.maximumValueSum(nums, 3, edges) << endl; // 6
}