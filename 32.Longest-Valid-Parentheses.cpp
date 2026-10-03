#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.length();
        stack<int> stack;
        stack.push(-1);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    result = max(result, i - stack.top());
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.longestValidParentheses(")()())") << endl; // 4
}