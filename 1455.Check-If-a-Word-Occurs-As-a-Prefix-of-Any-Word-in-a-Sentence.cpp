#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        const int n = sentence.length(), m = searchWord.length();
        int wordsCount = 1;
        int i = 0;
        while (i < n) {
            int j = 0;
            while (i < n && j < m && sentence[i] == searchWord[j]) {
                ++i, ++j;
            }
            if (j == m) return wordsCount;

            while (i < n && sentence[i] != ' ') ++i;
            ++i;
            ++wordsCount;
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    cout << solution.isPrefixOfWord("i love eating burger", "burg") << endl; // 4
}