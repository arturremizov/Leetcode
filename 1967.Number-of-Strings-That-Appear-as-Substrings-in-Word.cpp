#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        for (string pattern : patterns) {
            if (hasPatternInWord(pattern, word)) {
                ++result;
            }
        }
        return result;
    }
private:
    bool hasPatternInWord(const string& pattern, const string& word) {
        const int n = word.length(), m = pattern.length();
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && word[i + j] == pattern[j]) {
                ++j;
            }   
            if (j == m) return true;
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<string> patterns = {"a","abc","bc","d"};
    cout << solution.numOfStrings(patterns, "abc") << endl; // 3
}