#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    vector<vector<vector<int>>> memo;
public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int rows = coins.size(), cols = coins[0].size();
        memo.assign(rows, vector<vector<int>>(cols, vector<int>(3, INT_MIN)));
        return dfs(0, 0, 2, coins);
    }
private:
    int dfs(int row, int col, int k, vector<vector<int>>& coins) {
        const int rows = coins.size(), cols = coins[0].size();
        if (row >= rows || col >= cols) return INT_MIN;

        if (row == rows - 1 && col == cols - 1) {
            if (coins[row][col] < 0 && k > 0) return 0;
            return coins[row][col];
        }

        if (memo[row][col][k] != INT_MIN) return memo[row][col][k];

        int result = coins[row][col];
        result += max(
            dfs(row, col + 1, k, coins),
            dfs(row + 1, col, k, coins)
        );

        if (coins[row][col] < 0 && k > 0) {
            result = max(
                result,
                max(
                    dfs(row, col + 1, k - 1, coins),
                    dfs(row + 1, col, k - 1, coins)
                )
            );
        } 
        return memo[row][col][k] = result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> coins = {
        {0,1,-1},
        {1,-2,3},
        {2,-3,4}
    };
    cout << solution.maximumAmount(coins) << endl; // 8
}