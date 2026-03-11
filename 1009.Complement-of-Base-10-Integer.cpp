#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int mask = 0;
        int num = n;
        while (num > 0) {
            mask <<= 1;
            mask |= 1;
            num >>= 1;
        }
        return n ^ mask;
    }
};

int main() {
    Solution solution; 
    cout << solution.bitwiseComplement(5) << endl; // 2
}
 