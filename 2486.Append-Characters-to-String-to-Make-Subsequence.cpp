#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (j >= t.length()) break; 
            if (s[i] == t[j]) {
                ++j;
            }
        }
        return t.length() - j;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.appendCharacters("coaching", "coding") << endl; // 4
    cout << solution.appendCharacters("abcde", "a") << endl; // 0
    cout << solution.appendCharacters("z", "abcde") << endl; // 5
};