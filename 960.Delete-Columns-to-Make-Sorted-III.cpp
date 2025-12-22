#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int m = strs[0].size();
        vector<int> memo(m, -1);
        int validLength = 0;
        for (int col = 0; col < m; ++col) {
            validLength = max(validLength, dfs(col, strs, memo));
        }
        return m - validLength;
    }
private:
    int dfs(int i, vector<string>& strs, vector<int>& memo) {
        const int n = strs.size(), m = strs[0].size();
        if (memo[i] != -1) return memo[i];

        int validLength = 1;
        for (int col = i + 1; col < m; ++col) {
            bool isValid = true;
            for (int row = 0; row < n; ++row) {
                if (strs[row][i] > strs[row][col]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                validLength = max(validLength, 1 + dfs(col, strs, memo));
            }
        }
        memo[i] = validLength;
        return validLength;
    }
};

int main() {
    Solution solution; 
    vector<string> strs = {"babca","bbazb"};
    cout << solution.minDeletionSize(strs) << endl; // 3
}