#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int n;
public:
    int numberOfSets(int n, int k) {
        this->n = n;
        vector<vector<vector<int>>> memo = vector(n, vector(k + 1, vector(2, -1)));
        return dfs(0, k, true, memo);
    }
private:
    const int MOD = 1e9+7;
    int dfs(int i, int k, bool isNewSegment, vector<vector<vector<int>>>& memo) {
        if (k == 0 && isNewSegment) return 1;
        if (i == n) return 0;
        if (memo[i][k][isNewSegment] != -1) return memo[i][k][isNewSegment];

        long long result = 0;
        if (isNewSegment) {
            result = dfs(i + 1, k, true, memo); // skip point
            result += dfs(i + 1, k - 1, false, memo); // start new segment here
        } else {
            result = dfs(i, k, true, memo); // end segment here
            result += dfs(i + 1, k, false, memo); // continue segment
        }
        return memo[i][k][isNewSegment] = result % MOD;
    }
};

int main() {
    Solution solution; 
    cout << solution.numberOfSets(4,2) << endl; // 5
}