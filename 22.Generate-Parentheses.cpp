#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        backtrack(0, 0, n, s, result);
        return result;
    }
private:
    void backtrack(int open, int closed, const int n, string& s, vector<string>& result) {
        if (closed == n) {
            result.push_back(s);
            return;
        }
        if (open < n) {
            s += '(';
            backtrack(open + 1, closed, n, s, result);
            s.pop_back();
        } 
        if (open > closed) {
            s += ')';
            backtrack(open, closed + 1, n, s, result);
            s.pop_back();
        }
    }
};

int main() {
    Solution solution; 
    vector<string> result = solution.generateParenthesis(3); // "((()))","(()())","(())()","()(())","()()()"
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}