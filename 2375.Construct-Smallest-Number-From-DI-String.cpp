#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        const int n = pattern.length();
        string result;
        stack<int> stack;
        for (int i = 0; i < n + 1; ++i) {
            stack.push(i + 1);
            while (!stack.empty() && (i == n || pattern[i] == 'I')) {
                result += to_string(stack.top());
                stack.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestNumber("IIIDIDDD") << endl; // "123549876"
}