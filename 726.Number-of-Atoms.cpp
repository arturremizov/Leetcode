#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());
        int i = 0;
        while (i < formula.length()) {
            if (formula[i] == '(') {
                stack.push(unordered_map<string, int>());
            } else if (formula[i] == ')') {
                unordered_map<string, int> current_map = stack.top();
                stack.pop();
                
                int count = getCount(i, formula);
                unordered_map<string, int> prev_map = stack.top();
                stack.pop();
                for (auto [element, _] : current_map) {
                    prev_map[element] += current_map[element] * count;
                }
                stack.push(prev_map);
            } else {
                string element {formula[i]};
                if (i + 1 < formula.length() && islower(formula[i + 1])) {
                    element += formula[i + 1];
                    ++i;
                }
                int count = getCount(i, formula);
                stack.top()[element] += count;
            }
            ++i;
        }
        
        unordered_map<string, int> map = stack.top();
        vector<string> elements;
        for (auto [key, _] : map) {
            elements.push_back(key);
        }
        sort(elements.begin(), elements.end());

        string result;
        for (string element : elements) {
            string count = "";
            if (map[element] > 1) {
                count = to_string(map[element]);
            }
            result += element + count;
        }
        return result;
    }
private:
    int getCount(int& i, string formula) {
        string countStr = "";
        while (i + 1 < formula.length() && isdigit(formula[i + 1])) {
            countStr += formula[i + 1];
            ++i;
        }
        if (countStr.empty()) {
            return 1;
        } else {
            return stoi(countStr);
        }
    }
};

int main() 
{
    Solution solution; 
    cout << solution.countOfAtoms("H2O") << endl; // "H2O"
    cout << solution.countOfAtoms("Mg(OH)2") << endl; // "H2MgO2"
    cout << solution.countOfAtoms("K4(ON(SO3)2)2") << endl; // "K4N2O14S4"
}