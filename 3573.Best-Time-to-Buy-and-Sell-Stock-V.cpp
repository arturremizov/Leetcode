#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const int n = prices.size();
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(3, vector<long long>(k + 1, LLONG_MIN)));
        return dfs(0, FLAT, prices, k, memo);
    }
private:
    enum State {
        FLAT = 0,
        HOLDING_LONG = 1, 
        HOLDING_SHORT = 2
    };
    long long dfs(int day, State state, vector<int>& prices, int k,
                  vector<vector<vector<long long>>>& memo) {
        if (k == 0) return 0;
        if (day == prices.size()) {
            return state == FLAT ? 0 : LLONG_MIN / 4;
        }
        if (memo[day][state][k] != LLONG_MIN) {
            return memo[day][state][k];
        }

        long long result = dfs(day + 1, state, prices, k, memo); // skip
        if (state == HOLDING_LONG) {
            result = max(result,
                // Sell (complete long)
                prices[day] + dfs(day + 1, FLAT, prices, k - 1, memo)
            );
        } else if (state == HOLDING_SHORT) {
            result = max(
                result,
                // Buy back (complete short)
                -prices[day] + dfs(day + 1, FLAT, prices, k - 1, memo)
            );
        } else {
            result = max({
                result,
                -prices[day] + dfs(day + 1, HOLDING_LONG, prices, k, memo),
                prices[day] + dfs(day + 1, HOLDING_SHORT, prices, k, memo),
            });
        }
        memo[day][state][k] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> prices = {1,7,9,8,2};
    cout << solution.maximumProfit(prices, 2) << endl; // 14
}