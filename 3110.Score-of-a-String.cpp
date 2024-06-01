#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (int i = 1; i < s.length(); ++i) {
            result += abs(s[i - 1] - s[i]);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.scoreOfString("hello") << endl; // 13
    cout << solution.scoreOfString("zaz") << endl; // 50
}