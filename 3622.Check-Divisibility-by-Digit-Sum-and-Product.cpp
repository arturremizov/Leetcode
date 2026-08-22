#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int curNum = n;
        while (curNum) {
            int digit = curNum % 10;
            curNum /= 10;
            sum += digit;
            product *= digit;
        }
        return n % (sum + product) == 0;
    }
};

int main() {
    Solution solution; 
    cout << solution.checkDivisibility(99) << endl; // true
}