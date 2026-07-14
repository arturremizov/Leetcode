#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int n = nums.size();
        vector memo(n, vector(201, vector(201, -1)));
        return dfs(0, 0, 0, nums, memo) - 1;
    }
private:
    const int MOD = 1e9 + 7;
    int dfs(int i, int leftGcd, int rightGcd, vector<int>& nums, vector<vector<vector<int>>>& memo) {
        if (i == nums.size()) return leftGcd == rightGcd;
        if (memo[i][leftGcd][rightGcd] != -1) {
            return memo[i][leftGcd][rightGcd];
        }
        int result = dfs(i + 1, leftGcd, rightGcd, nums, memo) % MOD; // skip
        result = (result + dfs(i + 1, gcd(nums[i], leftGcd), rightGcd, nums, memo)) % MOD; // take to left
        result = (result + dfs(i + 1, leftGcd, gcd(nums[i], rightGcd), nums, memo)) % MOD; // take to right
        return memo[i][leftGcd][rightGcd] = result;
    }
    int gcd(int a, int b) {
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4};
    cout << solution.subsequencePairCount(nums) << endl; // 10
}