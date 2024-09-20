#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        long long prefix = 0;
        long long suffix = 0;
        int base = 29;
        int lastIndex = 0;
        long long power = 1;
        long long mod = 1e9 + 7;

        for (int i = 0; i < s.length(); i++) {
            int value = s[i] - 'a' + 1;
            prefix = (prefix * base) % mod;
            prefix = (prefix + value) % mod;

            suffix = (suffix + value * power) % mod;
            power = (power * base) % mod;

            if (prefix == suffix) {
                lastIndex = i;
            }
        }

        string suffixToAdd = s.substr(lastIndex + 1); 
        reverse(suffixToAdd.begin(), suffixToAdd.end());
        return suffixToAdd + s;
    }
};

int main() {
    Solution solution; 
    cout << solution.shortestPalindrome("abcd") << endl; // "dcbabcd"
}