#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        vector<int> charCount(26);
        for (char c : s) {
            charCount[c - 'a']++;
        }
        string result;
        int currentMinChar = 0;
        stack<int> stack;
        for (char c : s) {
            int value = c - 'a';
            stack.push(value);
            charCount[value]--;

            while (currentMinChar < 25 && charCount[currentMinChar] == 0) {
                currentMinChar++;
            }
            while (!stack.empty() && stack.top() <= currentMinChar) {
                result += (char)(stack.top() + 'a');
                stack.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.robotWithString("bac") << endl; // "abc"
}