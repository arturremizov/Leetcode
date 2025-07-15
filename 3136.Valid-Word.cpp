#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        bool hasVowel = false, hasConstant = false;
        for (char c : word) {
            char lowerChar = tolower(c);
            if (vowels.count(lowerChar)) {
                hasVowel = true;
            } else if (lowerChar - 'a' >= 0 && lowerChar - 'a' < 26) {
                hasConstant = true;
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConstant;
    }
};

int main() {
    Solution solution; 
    cout << solution.isValid("234Adas") << endl; // true
}