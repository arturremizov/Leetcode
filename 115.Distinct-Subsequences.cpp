#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int n = s.length(), m = t.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dfs(0, 0, s, t, memo);
    }
private:
    int dfs(int i, int j, const string &s, const string &t, vector<vector<int>>& memo) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int result = 0;
        if (s[i] == t[j]) {
            result = dfs(i + 1, j + 1, s, t, memo) + dfs(i + 1, j, s, t, memo);
        } else {
            result = dfs(i + 1, j, s, t, memo);
        }
        return memo[i][j] = result;
    }
};

int main() {
    Solution solution; 
    cout << solution.numDistinct("babgbag", "bag") << endl; // 5
}