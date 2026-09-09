#include <iostream>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;
        long long commaThreshold = 1000;
        while (n >= commaThreshold) {
            result += n - commaThreshold + 1;
            commaThreshold *= 1000;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countCommas(1004590) << endl; // 1008182
}