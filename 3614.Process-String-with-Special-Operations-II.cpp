#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        for (char c : s) {
            if (islower(c)) {
                ++length;
            } else if (c == '*') {
                if (length > 0) {
                    --length;
                }
            } else if (c == '#') {
                length += length;
            } 
        }
        
        if (k >= length) return '.';

        for (int i = s.length() - 1; i >=0; --i) {
            if (s[i] == '*') {
                ++length; 
            } else if (s[i] == '#') {
                long long half = length / 2;
                if (k >= half) {
                    k -= half;
                }
                length = half;
            } else if (s[i] == '%') {
                k = length - k - 1;
            } else {
                if (k == length - 1) {
                    return s[i];
                } else {
                    --length;
                }
            }
        }
        return '.';
    }
};

int main() {
    Solution solution; 
    cout << solution.processStr("cd%#*#", 3) << endl; // d
}