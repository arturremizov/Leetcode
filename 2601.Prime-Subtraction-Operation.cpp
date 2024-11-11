#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;
        for (int num : nums) {
            int upperBound = num - prev - 1;
            int largestPrime = 0;
            for (int i = upperBound; i >= 2; --i) {
                if (isPrime(i)) {
                    largestPrime = i;
                    break;
                }
            }
            if (num - largestPrime <= prev) {
                return false;
            }
            prev = num - largestPrime;
        }
        return true;
    }
private:
    bool isPrime(int num) {
        for (int i = 2; i < (int)sqrt(num) + 1; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,9,6,10};
    cout << solution.primeSubOperation(nums) << endl; // true
}