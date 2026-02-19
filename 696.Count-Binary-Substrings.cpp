#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        const int n = s.length();
        int prevGroup = 0, currGroup = 1;
        int result = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == s[i]) {
                ++currGroup;
            } else {
                result += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }       
        result += min(prevGroup, currGroup);
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countBinarySubstrings("00110011") << endl; // 6
}