#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string result;
        for (char c : s) {
            if (isdigit(c)) {
                result.pop_back();
            } else {
                result += c;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.clearDigits("acb34") << endl; // "a"
}