#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] == '0' && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    cout << solution.checkOnesSegment("110") << endl; // true
}