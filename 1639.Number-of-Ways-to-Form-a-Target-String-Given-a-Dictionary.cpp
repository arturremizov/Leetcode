#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordsLength = words[0].length();
        int targetLength = target.length();

        vector<vector<int>> charCount(wordsLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < wordsLength; ++i) {
                charCount[i][word[i] - 'a']++;
            }
        }

        unordered_map<string, int> memo;
        return dfs(0, 0, target, charCount, memo);
    }
private:
    const int MOD = 1e9 + 7;

    // i - index of target char, k - index of words char
    int dfs(int i, int k, string& target, vector<vector<int>>& charCount,   
            unordered_map<string, int>& memo) {

        string key = to_string(i) + "," + to_string(k);
        if (memo.count(key)) return memo[key];
 
        if (i == target.length()) {
            return 1;
        }
        if (k == charCount.size()) {
            return 0;
        }
        
        int targetCharIndex = target[i] - 'a';
        int charCountInWords = charCount[k][targetCharIndex];

        // skip
        int result = dfs(i, k + 1, target, charCount, memo) % MOD;

        // include 
        if (charCountInWords > 0) {
            int includeResult = dfs(i + 1, k + 1, target, charCount, memo) % MOD;
            result = (result + (((long)charCountInWords * includeResult) % MOD)) % MOD;
        }
        memo[key] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"acca","bbbb","caca"};
    cout << solution.numWays(words, "aba") << endl; // 6
}