#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int result = 0;
        if (x > y) {
            result += removePairs(s, "ab", x);
            result += removePairs(s, "ba", y);
        } else {
            result += removePairs(s, "ba", y);
            result += removePairs(s, "ab", x);
        }
        return result;
    }
private:
    int removePairs(string& s, string pair, int score) {
        int result = 0;
        stack<char> stack;
        for (char c : s) {
            if (c == pair[1] && !stack.empty() && stack.top() == pair[0]) {
                stack.pop();
                result += score;
            } else {
                stack.push(c);
            }
        }
        s = "";
        while (!stack.empty()) {
            s += stack.top();
            stack.pop();
        }
        reverse(s.begin(), s.end());
        return result;
    } 
};

int main() 
{
    Solution solution; 
    cout << solution.maximumGain("cdbcbbaaabab", 4, 5) << endl; // 19
    cout << solution.maximumGain("aabbaaxybbaabb", 5, 4) << endl; // 20
}