#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        const int n = str1.length(), m = str2.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int a = str1[i] - 'a';
            int b = str2[j] - 'a';
            if (a == b || (a + 1 == b) || (a + 1 == 26 && b == 0)) {
                ++i, ++j;
            } else {
                ++i;
            }
        }
        return j == m;
    }
};

int main() {
    Solution solution; 
    cout << solution.canMakeSubsequence("dby", "z") << endl; // true
}