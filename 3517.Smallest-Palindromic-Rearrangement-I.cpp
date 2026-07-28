#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        const int n = s.length();
        vector<int> chars(26);
        for (char c : s) {
            chars[c - 'a']++;
        }
        int left = 0, right = n - 1;
        for (int i = 0; i < 26; ++i) {
            if (chars[i] == 0) continue;
            int count = chars[i] / 2;
            while (count--) {
                char c = 'a' + i;
                s[left++] = c;
                s[right--] = c;
            }
        }
        return s;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestPalindrome("daccad") << endl; // "acddca"
}