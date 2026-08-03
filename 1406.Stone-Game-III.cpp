#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> memo(stoneValue.size(), INT_MIN);
        int difference = dfs(0, stoneValue, memo);
        if (difference > 0) return "Alice";
        if (difference < 0) return "Bob";
        return "Tie";
    }
private:
    int dfs(int i, vector<int>& stoneValue, vector<int>& memo) {
        const int n = stoneValue.size();
        if (i == n) return 0;
        if (memo[i] != INT_MIN) return memo[i];
        int result = INT_MIN;
        int take = 0;
        for (int j = i; j < min(i + 3, n); ++j) {
            take += stoneValue[j];
            result = max(result, take - dfs(j + 1, stoneValue, memo));
        } 
        return memo[i] = result;
    }
};

int main() {
    Solution solution; 
    vector<int> piles = {1,2,3,7};
    cout << solution.stoneGameIII(piles) << endl; // "Bob"
}