#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dfs(0, 0, s1, s2, memo);
    }
private:
    int dfs(int i, int j, const string& s1, const string& s2, vector<vector<int>>& memo) {
        const int n = s1.size(), m = s2.size();
        if (i == n) {
            int sum = 0;
            for (int k = j; k < m; ++k) sum += s2[k];
            return sum;
        }
        if (j == m) {
            int sum = 0;
            for (int k = i; k < n; ++k) sum += s1[k];
            return sum;
        }

        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j]) {
            return dfs(i + 1, j + 1, s1, s2, memo);
        }

        return memo[i][j] = min(
            s1[i] + dfs(i + 1, j, s1, s2, memo),
            s2[j] + dfs(i, j + 1, s1, s2, memo)
        );
    }
};

int main() {
    Solution solution; 
    cout << solution.minimumDeleteSum("delete", "leet") << endl; // 403
}