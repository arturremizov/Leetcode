#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution solution; 
    cout << solution.maximum69Number(9669) << endl; // 9969
}