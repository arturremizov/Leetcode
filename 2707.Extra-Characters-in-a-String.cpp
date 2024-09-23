#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        unordered_map<int, int> memo;
        return dfs(s, words, 0, memo);
    }
private:
    int dfs(string s, unordered_set<string>& words, int i, unordered_map<int, int>& memo) {
        if (memo.count(i)) return memo[i];
        if (i == s.length()) return 0;

        int result = 1 + dfs(s, words, i + 1, memo);
        for (int j = i; j < s.length(); j++) {
            string substr = s.substr(i, j - i + 1);
            if (words.count(substr)) {
                result = min(result, dfs(s, words, j + 1, memo));
            }
        }
        memo[i] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> dictionary = {"leet","code","leetcode"};
    cout << solution.minExtraChar("leetscode", dictionary) << endl; // 1
}