#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (int)pow(3, 19) % n == 0;
    }
};

int main() {
    Solution solution; 
    cout << solution.isPowerOfThree(27) << endl; // true
}