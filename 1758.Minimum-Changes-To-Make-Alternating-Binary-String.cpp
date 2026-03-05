#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        const int n = s.length();
        int evenCount = 0, oddCount = 0; // even = 1010; odd = 0101
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i % 2 == 0) {
                    ++evenCount;
                } else {
                    ++oddCount;
                }
            } else if (s[i] == '1') {
                if (i % 2 == 0) {
                    ++oddCount;
                } else {
                    ++evenCount;
                }
            }
        }
        return min(evenCount, oddCount);
    }
};

int main() {
    Solution solution; 
    cout << solution.minOperations("0100") << endl; // 1
}