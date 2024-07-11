#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        const int n = s.length();
        
        unordered_map<int, int> pairs;
        stack<int> stack;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')') {
                int j = stack.top();
                stack.pop();
                pairs[j] = i;
                pairs[i] = j;
            }
        }

        string result;
        int i = 0, direction = 1;

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pairs[i];
                direction = -direction;
            } else {
                result += s[i];
            }
            i += direction;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.reverseParentheses("(abcd)") << endl; // dcba
    cout << solution.reverseParentheses("(u(love)i)") << endl; // iloveu
    cout << solution.reverseParentheses("(ed(et(oc))el)") << endl; // leetcode
}