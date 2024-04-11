#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        for (char c : num) {
            while (k > 0 && !stack.empty() && stack.back() > c) {
                k--;
                stack.pop_back();
            }
            stack.push_back(c);
        }
        int length = stack.size() - k;
        stack.erase(stack.begin() + length, stack.end());
        while (stack.size() > 1 && stack.front() == '0') {
            stack.erase(stack.begin());
        }
        string result(stack.begin(), stack.end());
        return result.empty() ? "0" : result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.removeKdigits("1432219", 3) << endl;
    cout << solution.removeKdigits("10200", 1) << endl;
    cout << solution.removeKdigits("10", 2) << endl;
}