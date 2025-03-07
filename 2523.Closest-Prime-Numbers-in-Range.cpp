#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = getPrimes(left, right);
        vector<int> result = {-1, -1};
        int minRange = INT_MAX;
        for (int i = 1; i < primes.size(); ++i) {
            if (primes[i] - primes[i - 1] < minRange) {
                minRange = primes[i] - primes[i - 1];
                result = {primes[i - 1], primes[i]};
            }
        }
        return result;
    }
private:
    vector<int> getPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= sqrt(right); ++i) {
            if (!isPrime[i]) continue;
            for (int j = i + i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (isPrime[i]) {
                cout << i << endl;
                primes.push_back(i);
            }
        }
        return primes;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.closestPrimes(10, 19); //[11,13]
    cout << "[" << result[0] << "," << result[1] << "]\n";
}