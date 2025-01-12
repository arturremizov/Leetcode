#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> lockedStack;
        stack<int> unlockedStack;

        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0') {
                unlockedStack.push(i);
            } else {
                if (s[i] == '(') {
                    lockedStack.push(i);
                } else {
                    if (!lockedStack.empty()) {
                        lockedStack.pop();
                    } else if (!unlockedStack.empty()) {
                        unlockedStack.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        while (!lockedStack.empty() && !unlockedStack.empty() &&
                lockedStack.top() < unlockedStack.top()) {
            
            lockedStack.pop();
            unlockedStack.pop();
        }
        
        if (!lockedStack.empty()) {
            return false;
        }

        return unlockedStack.size() % 2 == 0 ? true : false;
    }
};

int main() {
    Solution solution; 
    cout << solution.canBeValid("))()))", "010100") << endl; // true
}