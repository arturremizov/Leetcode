#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        const int n = word.length();
        vector<int> lastLowercase(26, -1), firstUpercase(26, -1);
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (islower(c)) {
                lastLowercase[c - 'a'] = i;
            } else {
                if (firstUpercase[c - 'A'] == -1) {
                    firstUpercase[c - 'A'] = i;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (lastLowercase[i] == -1 || firstUpercase[i] == -1) continue;
            if (lastLowercase[i] < firstUpercase[i]) {
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