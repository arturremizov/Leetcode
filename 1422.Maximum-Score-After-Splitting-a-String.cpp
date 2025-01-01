#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zero = 0;
        int one = 0;
        for (char c : s) {
            if (c == '1') ++one;
        }

        int result = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '1') {
                --one;
            } else {
                ++zero;
            }
            result = max(result, zero + one);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxScore("011101") << endl; // 5
}