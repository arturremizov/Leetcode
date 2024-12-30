#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<int, int> memo;
        return dfs(0, low, high, zero, one, memo);
    }
private:
    const int MOD = 1e9 + 7;
    int dfs(int length, int low, int high, int zero, int one, unordered_map<int, int>& memo) {
        if (memo.count(length)) return memo[length];
        if (length > high) return 0;
        int result = length >= low ? 1 : 0;
        result += dfs(length + zero, low, high, zero, one, memo) +
                  dfs(length + one, low, high, zero, one, memo);

        memo[length] = result % MOD;
        return memo[length];
    }
};

int main() {
    Solution solution; 
    cout << solution.countGoodStrings(3,3,1,1) << endl; // 8
}