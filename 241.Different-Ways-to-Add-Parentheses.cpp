#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return backtrack(expression, 0, expression.length() - 1);
    }
private:
    vector<int> backtrack(string expression, int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            char operation = expression[i];
            if (operation == '-' || operation == '*' || operation == '+') {
                vector<int> nums1 = backtrack(expression, left, i - 1);
                vector<int> nums2 = backtrack(expression, i + 1, right);
                for (int num1 : nums1) {
                    for (int num2 : nums2) {
                        switch (operation){
                        case '-':
                            result.push_back(num1 - num2);
                            break;
                        case '*':
                            result.push_back(num1 * num2);
                            break;
                        case '+':
                            result.push_back(num1 + num2);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(expression.substr(left, right - left + 1)));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.diffWaysToCompute("2-1-1"); // [0,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}