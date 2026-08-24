#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    int n;
public:
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        vector<int> memo(n, INT_MIN);
        return dfs(1, prefix, memo);
    }
private:
    int dfs(int i, vector<int>& prefix, vector<int>& memo) {
        if (i == n - 1) return prefix[i];
        if (memo[i] != INT_MIN) return memo[i];
        int next = dfs(i + 1, prefix, memo); // select next score (x + 1)
        int choose = prefix[i] - next; // select current score and get score difference
        return memo[i] = max(next, choose);
    }
};

int main() {
    Solution solution; 
    vector<int> stones = {-1,2,-3,4,-5};
    cout << solution.stoneGameVIII(stones) << endl; // 5
}