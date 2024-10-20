#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return helper(expression, i);
    }
private:
    bool helper(string& expression, int& i) {
        char c = expression[i];
        ++i;
        if (c == 't') return true;
        if (c == 'f') return false;
        if (c == '!') {
            ++i;
            bool result = !helper(expression, i);
            ++i;
            return result;
        }

        vector<bool> values;
        ++i;
        while (expression[i] != ')') {
            if (expression[i] == ',') {
                ++i;
                continue;
            }
            values.push_back(helper(expression, i));
        }
        ++i;

        bool result = values[0];
        if (c == '&') {
            for (int i = 1; i < values.size(); ++i) {
                result = result & values[i];
            }
        }

        if (c == '|') {
            for (int i = 1; i < values.size(); ++i) {
                result = result | values[i];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.parseBoolExpr("&(|(f))") << endl; // false
}