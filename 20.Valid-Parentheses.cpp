#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> pairs = {
            {'(',')'}, {'[',']'}, {'{','}'},
        };
        stack<char> stack;
        for (char c : s) {
            if (!stack.empty() && pairs[stack.top()] == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution solution; 
    cout << solution.isValid("()[]{}") << endl; // true
}