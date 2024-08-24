#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        const int length = n.length();
        bool isEven = length % 2 == 0;

        int midIndex = isEven ? length / 2 - 1 : length / 2;
        long leftPart = stol(n.substr(0, midIndex + 1));
        
        vector<long> possibilities = {
            makePalindrome(leftPart, isEven),
            makePalindrome(leftPart - 1, isEven),
            makePalindrome(leftPart + 1, isEven),
            (long)pow(10, length - 1) - 1,
            (long)pow(10, length) + 1
        };

        const long num = stol(n);
        long result = 0, difference = LONG_MAX;
        for (long candidate : possibilities) {
            if (candidate == num) continue;
            if (abs(num - candidate) < difference) {
                result = candidate;
                difference = abs(num - candidate);
            } else if (abs(num - candidate) == difference) {
                result = min(result, candidate);
            }
        }
        return to_string(result);
    }
private:
    long makePalindrome(long leftPart, bool isEven) {
        long result = leftPart;
        if (!isEven) {
            leftPart /= 10;
        }
        while (leftPart > 0) {
            result = result * 10 + leftPart % 10;
            leftPart /= 10;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.nearestPalindromic("12345") << endl; // "12321"
    cout << solution.nearestPalindromic("1394") << endl; // "1441"
}