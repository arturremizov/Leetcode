#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        const int n = s.length();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> charCount(26);
            for (int j = i; j < n; ++j) {
                bool isBalanced = true;
                int charIndex = s[j] - 'a';
                charCount[charIndex]++;
                for (int count : charCount) {
                    if (count > 0 && count != charCount[charIndex]) {
                        isBalanced = false;
                        break;
                    }
                }
                if (isBalanced) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.longestBalanced("abbac") << endl; // 4
}