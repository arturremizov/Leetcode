#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int n = s.length(), m = spaces.size();
        string result;
        result.reserve(n + m);
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (i < spaces[j]) {
                result += s[i];
                ++i;
            } else {
                result += ' ';
                ++j;
            }
        }
        if (i < n) {
            result.append(s.substr(i, n - i));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> spaces = {8,13,15};
    cout << solution.addSpaces("LeetcodeHelpsMeLearn", spaces) << endl; //"Leetcode Helps Me Learn"
}