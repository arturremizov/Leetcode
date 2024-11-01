#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        result.push_back(s[0]);
        char prev = s[0];
        int count = 1;
        for (int i = 1; i < s.length(); ++i) {
            char c = s[i];
            if (c == prev) {
                count++;
            } else {
                count = 1;
                prev = c;
            }
            if (count < 3) {
                result.push_back(c);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.makeFancyString("aaabaaaa") << endl; // "aabaa"
}