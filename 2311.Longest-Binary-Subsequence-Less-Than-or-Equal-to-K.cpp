#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        const int n = s.length();
        int currentNum = 0;
        int result = count(s.begin(), s.end(), '0');
        for (int i = 0; i < min(31, n); ++i) {
            if (s[n - i - 1] == '1') {
                currentNum |= 1 << i;
                if (currentNum > k) break;
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.longestSubsequence("1001010", 5) << endl; // 5
}