#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubledString = s + s;
        return doubledString.find(goal) < doubledString.length();
    }
};

int main() {
    Solution solution; 
    cout << solution.rotateString("abcde", "cdeab") << endl; // true
}