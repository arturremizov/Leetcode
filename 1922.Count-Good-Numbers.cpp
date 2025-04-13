#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int countGoodNumbers(long long n) {
        long long even = ceil(n / 2.0);
        long long odd = n / 2;
        return (pow(5, even) * pow(4, odd)) % MOD;
    }
private:
    long long pow(long long x, long long n) {
        if (n == 0) return 1;
        long long result = 1;
        while (n > 1) {
            if (n % 2 != 0) {
                result = (result * x) % MOD;
            }
            n /= 2;
            x = (x * x) % MOD;
        }
        return (result * x) % MOD;
    }
};

int main() {
    Solution solution; 
    cout << solution.countGoodNumbers(4) << endl; // 400
}