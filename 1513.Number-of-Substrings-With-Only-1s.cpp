#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        int result = 0;
        int currSubstrSize = 0;
        for (char c : s) {
            if (c == '1') {
                result = (result + ++currSubstrSize) % MOD;
            } else {
                currSubstrSize = 0;
            }
        } 
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.numSub("0110111") << endl; // 9
}
