#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        const int n = s.length();
        s += s;
        string alt1, alt2;
        for (int i = 0; i < n * 2; ++i) {
            alt1 += i % 2 == 0 ? "1" : "0";
            alt2 += i % 2 == 0 ? "0" : "1";
        }

        int diff1 = 0, diff2 = 0;
        int result = n;
        int left = 0;
        for (int right = 0; right < n * 2; ++right) {
            if (s[right] != alt1[right]) {
                ++diff1;
            } 
            if (s[right] != alt2[right]) {
                ++diff2;
            } 

            if ((right - left + 1) > n) {
                if (s[left] != alt1[left]) {
                    --diff1;
                } 
                if (s[left] != alt2[left]) {
                    --diff2;
                } 
                ++left;
            }

            if ((right - left + 1) == n) {
                result = min({result, diff1, diff2});
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minFlips("111000") << endl; // 2
}