#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> letters;
        for (char c : brokenLetters) {
            letters.insert(c);
        }
        int result = 0;
        bool canType = true;
        for (char c : text) {
            if (c == ' ') {
                result += canType;
                canType = true;
                continue;
            }
            if (letters.count(c)) {
                canType = false;
            }
        }
        result += canType;
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.canBeTypedWords("hello world", "ad") << endl; // 1
}