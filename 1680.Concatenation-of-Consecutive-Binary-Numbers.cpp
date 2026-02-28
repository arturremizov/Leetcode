#include <iostream>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        int bitLength = 0;
        long long result = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++bitLength;
            result = ((result << bitLength) | i) % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.concatenatedBinary(12) << endl; // 505379714
}