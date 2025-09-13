#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> charCount(26);
        int maxVowelCount = 0;
        int maxConsonantCount = 0;
        for (char c : s) {
            int charIndex = c - 'a';
            charCount[charIndex]++;
            if (isVowel(c)) {
                maxVowelCount = max(maxVowelCount, charCount[charIndex]);
            } else {
                maxConsonantCount = max(maxConsonantCount, charCount[charIndex]);
            }
        }
        return maxVowelCount + maxConsonantCount;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main() {
    Solution solution; 
    cout << solution.maxFreqSum("successes") << endl; // 6
}