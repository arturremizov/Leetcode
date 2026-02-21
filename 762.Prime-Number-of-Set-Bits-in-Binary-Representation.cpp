#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int num = left; num <= right; ++num) {
            int bits = countBits(num);
            if (isPrime(bits)) {
                ++result;
            }
        }
        return result;
    }
private:
    int countBits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    bool isPrime(int num) {
        if (num < 2) return false;

        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    cout << solution.countPrimeSetBits(6, 10) << endl; // 4
}