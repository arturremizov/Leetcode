#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> memo(s.length(), -1);
        return dfs(0, s, memo);
    }
private:
    const int MOD = 1e9 + 7;
    int dfs(int i, const string& s, vector<int>& memo) {
        const int n = s.length();
        if (i == n) return 0;
        if (memo[i] != -1) return memo[i];
        int result = 0;
        bool visited[26] = {};
        for (int j = i; j < n; ++j) {
            int charIndex = s[j] - 'a';
            if (visited[charIndex]) continue;
            visited[charIndex] = true;
            result = (result + 1 + dfs(j + 1, s, memo)) % MOD;
        }
        return memo[i] = result;
    }
};

int main() {
    Solution solution; 
    cout << solution.distinctSubseqII("abc") << endl; // 7
}