#include <iostream>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = n * (n + 1);
        return gcd(sumEven, sumOdd);
    }
private:
    int gcd(int a, int b) {
        while (b) {
            int reminder = a % b;
            a = b;
            b = reminder;
        }
        return a;
    }
};

int main() {
    Solution solution; 
    cout << solution.gcdOfOddEvenSums(4) << endl; // 4
}