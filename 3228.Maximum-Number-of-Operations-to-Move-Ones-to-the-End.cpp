#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        const int n = s.length();
        int result = 0;
        int zeroWindowCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '1') {
                    ++zeroWindowCount;
                }
            } else {
                result += zeroWindowCount;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxOperations("1001101") << endl; // 4
}