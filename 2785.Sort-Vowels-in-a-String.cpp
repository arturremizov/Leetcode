#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        string result = s;
        for (int i = 0; i < s.length(); ++i) {
            if (!isVowel(s[i])) continue;
            result[i] = vowels[j++];
        }
        return result;
    }
private:
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main() {
    Solution solution;
    cout << solution.sortVowels("lEetcOde") << endl; // "lEOtcede"
}
