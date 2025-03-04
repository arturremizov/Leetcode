#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        return backtrack(0, 0, n);
    }
private:
    bool backtrack(int i, int currentSum, int n) {
        if (currentSum == n) return true;
        if (currentSum > n || pow(3, i) > n) return false;

        if (backtrack(i + 1, currentSum, n)) {
            return true;
        }
        return backtrack(i + 1, pow(3, i) + currentSum, n);
    }
};

int main() {
    Solution solution; 
    cout << solution.checkPowersOfThree(12) << endl; // true
}