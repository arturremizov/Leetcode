#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const int n = str1.size(), m = str2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string result = "";
        int i = n, j = m;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) {
                result = str1[i - 1] + result;
                --i, --j;
            } else if (j == 0 || (i > 0 && dp[i - 1][j] >= dp[i][j - 1])) {
                result = str1[i - 1] + result;
                --i;
            } else {
                result = str2[j - 1] + result;
                --j;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.shortestCommonSupersequence("abac","cab") << endl; // "cabac"
}