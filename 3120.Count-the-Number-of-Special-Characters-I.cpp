#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> chars(word.begin(), word.end());
        int result = 0;
        for (int i = 0; i <= 26; ++i) {
            if (chars.count(i + 'a') && chars.count(i + 'A')) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.numberOfSpecialChars("aaAbcBC") << endl; // 3
}