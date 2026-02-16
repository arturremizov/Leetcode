#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = (n >> i) & 1;
            bit = bit << (31 - i);
            result |= bit;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.reverseBits(43261596) << endl; // 964176192
}