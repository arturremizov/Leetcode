#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            for (int i = 0; i < s.length() - 1; ++i) {
                int num1 = s[i] - '0';
                int num2 = s[i + 1] - '0';
                s[i] = ((num1 + num2) % 10) + '0';
            }
            s.pop_back();
        }
        return s[0] == s[1];
    }
};

int main() {
    Solution solution; 
    cout << solution.hasSameDigits("3902") << endl; // true
}