#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return dp(1, n, x, memo);
    }
private:
    const int MOD = 1e9+7;
    int dp(int i, int sum, int x, vector<vector<int>>& memo) {
        int num = pow(i, x);
        if (num == sum) return 1;
        if (num > sum) return 0;
        if (memo[i][sum] != -1) return memo[i][sum];

        int result = dp(i + 1, sum, x, memo) % MOD; // skip
        result = (result + dp(i + 1, sum - num, x, memo)) % MOD; // include 
        memo[i][sum] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.numberOfWays(4, 1) << endl; // 2
}