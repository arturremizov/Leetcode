#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for (string detail : details) {
            int age = stoi(detail.substr(11,2));
            if (age > 60) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout << solution.countSeniors(details) << endl; // 2
}