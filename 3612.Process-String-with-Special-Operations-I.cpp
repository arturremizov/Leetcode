#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                result += c;
            } else if (c == '*') {
                if (result.empty()) continue;
                result.pop_back();
            } else if (c == '#') {
                result += result;
            } else if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.processStr("a#b%*") << endl; // "ba"
}