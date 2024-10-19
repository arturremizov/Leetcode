#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        int length = pow(2, n) - 1;
        return helper(length, k);
    }
private:
    char helper(int length, int k) {
        if (length == 1) return '0';

        int half = length / 2;
        if (k <= half) { // left
            return helper(half, k);
        } else if (k > half + 1) { // right
            char result = helper(half, 1 + length - k);
            return result == '1' ? '0' : '1';
        } else { // mid
            return '1';
        }
    }
};

int main() {
    Solution solution; 
    cout << solution.findKthBit(4,11) << endl; // '1'
}