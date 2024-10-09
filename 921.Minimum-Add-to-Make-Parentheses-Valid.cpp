#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int result = 0;
        for (char c : s) {
            if (c == '(') {
                ++openCount;
            } else {
                if (openCount == 0) {
                    ++result;
                } else {
                    --openCount;
                }
            }
        }
        return openCount + result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minAddToMakeValid("())") << endl; // 1
}