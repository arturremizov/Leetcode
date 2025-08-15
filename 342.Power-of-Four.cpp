#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
       if (n < 0) return false;
       return (n & (n - 1)) == 0 && (n & 1431655765) != 0; // 1431655765 -> 1010101010101010101010101010101 in binary 
    }
};

int main() {
    Solution solution; 
    cout << solution.isPowerOfFour(16) << endl; // true
}