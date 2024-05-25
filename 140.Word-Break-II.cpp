#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordsSet(wordDict.begin(), wordDict.end());
        vector<string> current;
        vector<string> result;
        backtrack(s, wordsSet, 0, current, result); 
        return result;
    }
private:
    void backtrack(string& s, unordered_set<string>& wordsSet, int i, vector<string>& current, vector<string>& result) {
        if (i == s.length()) {
            string resultString = accumulate(
                next(current.begin()),
                  current.end(),
                  current[0],
                  [](string a, string b) {
                    return a + " " + b;
                  }
                );

            result.push_back(resultString);
            return;
        }
        for (int j = i; j < s.length(); ++j) {
            string word = s.substr(i, j - i + 1);
            if (wordsSet.count(word)) {
                current.push_back(word);
                backtrack(s, wordsSet, j + 1, current, result);
                current.pop_back();
            }
        }
    }
};

int main() 
{
    Solution solution; 
    vector<int> deck = {17,13,11,2,3,5,7};
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    vector<string> result = solution.wordBreak("catsanddog", wordDict); // ["cats and dog","cat sand dog"]
    for (string s : result) {
        cout << s << endl;
    }
}