#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        const int n = s.length();
        unordered_map<string, string> keyToWord;
        for (auto& kn : knowledge) {
            keyToWord[kn[0]] = kn[1];
        }
        int i = 0;
        string result;
        while (i < n) {
            if (s[i] == '(') {
                int start = i;
                while (s[i] != ')') {
                    ++i;
                }
                string key = s.substr(start + 1, i - start - 1);
                string word = keyToWord.count(key) ? keyToWord[key] : "?";
                result += word;
                ++i;
            } else {
                result += s[i];
                ++i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<string>> knowledge = {{"name","bob"},{"age","two"}};
    cout << solution.evaluate("(name)is(age)yearsold",knowledge) << endl; // "bobistwoyearsold"
}