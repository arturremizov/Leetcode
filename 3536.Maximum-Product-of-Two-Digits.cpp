#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int digit1 = 0, digit2 = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            if (digit > digit1) {
                if (digit1 > digit2) {
                    digit2 = digit1;
                }
                digit1 = digit;
            } else if (digit > digit2) {
                digit2 = digit;
            }
        }
        return digit1 * digit2;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxProduct(124) << endl; // 8
}