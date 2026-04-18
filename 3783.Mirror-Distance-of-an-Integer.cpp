#include <iostream>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
private:
    int reverse(int num) {
        int reversedNum = 0;
        while (num > 0) {
            reversedNum *= 10;
            reversedNum += num % 10;
            num /= 10;
        }
        return reversedNum;
    }
};

int main() {
    Solution solution; 
    cout << solution.mirrorDistance(25) << endl; // 27
}