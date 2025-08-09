#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num = 1;
        while (num < n) {
            num *= 2;
        }
        return num == n;
    }
};

int main() {
    Solution solution; 
    cout << solution.isPowerOfTwo(16) << endl; // true
}