#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        for (char c : s) {
            
            if (!stack.empty() && 
                ((stack.top() == 'A' && c == 'B') || (stack.top() == 'C' && c == 'D'))) {

                stack.pop();
                continue;
            }
            stack.push(c);
        }
        return stack.size();
    }
};

int main() {
    Solution solution; 
    cout << solution.minLength("ABFCACDB") << endl; // 2
}