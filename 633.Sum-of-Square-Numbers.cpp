#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int left = 0;
        unsigned int right = sqrt(c);
        while (left <= right) {
            unsigned int total = left * left + right * right;
            if (total < c) {
                ++left;
            } else if (total > c) {
                --right;
            } else {
                return true;
            } 
        }
        return false;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.judgeSquareSum(5) << endl; // true
    cout << solution.judgeSquareSum(3) << endl; // false
}