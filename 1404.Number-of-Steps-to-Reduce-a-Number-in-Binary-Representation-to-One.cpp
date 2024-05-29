#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int result = 0;
        int carry = 0;
        const int n = s.length();
        for (int i = n-1; i > 0; --i) {
            int digit = (int(s[i]) + carry) % 2;
            if (digit == 0) {
                result += 1;
            } else if (digit == 1) {
                carry = 1;
                result += 2;
            }
        }
        return result + carry;
    }

    // int numSteps(string s) {
    //     int result = 0;
    //     while (s != "1") {
    //         if (s.back() == '0') {
    //             s.pop_back();
    //         } else {
    //             addOne(s);
    //         } 
    //         ++result;           
    //     }
    //     return result;
    // }
private:
    void addOne(string& s) {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0'; 
            --i;                       
        }

        if (i == -1) {
            s.insert(0, "1");
        } else {
            s[i] = '1';
        }
    }
};

int main() 
{
    Solution solution; 
    cout << solution.numSteps("1101") << endl; // 6
    cout << solution.numSteps("10") << endl; // 1
    cout << solution.numSteps("1") << endl; // 0
}