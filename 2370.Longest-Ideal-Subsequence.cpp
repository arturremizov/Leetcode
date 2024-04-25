#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (char c : s) {
            int current = c - 'a';
            int longest = 1;
            for (int prev = 0; prev < 26; ++prev) {
                if (abs(current - prev) <= k) {
                    longest = max(longest, 1 + dp[prev]);
                }
            }
            dp[current] = max(longest, dp[current]);
        }
        return  *max_element(dp.begin(), dp.end());
        // unordered_map<string, int> memo;
        // return dpMemo(s, k, 0, -1, memo);
    }
private:
    int dpMemo(string s, int k, int i, int prev, unordered_map<string, int> &memo) {
        string key = to_string(i) + "," + to_string(prev);
        if (memo.count(key)) return memo[key];
        if (i == s.size()) return 0;
        int result = dpMemo(s, k, i + 1, prev, memo); // skip i
        if (prev == -1 || abs(int(s[i]) - int(s[prev])) <= k) {
            result = max(result, 1 + dpMemo(s, k, i + 1, i, memo)); // include i
        }
        memo[key] = result;
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.longestIdealString("acfgbd", 2) << endl; // 4
    cout << solution.longestIdealString("abcd", 3) << endl; // 4
}