#include <iostream>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;
        for (int num = 1; num <= n; ++num) {
            if (num % m != 0) {
                num1 += num;
            } else {
                num2 += num;        
            }
        }
        return num1 - num2;
    }
};

int main() {
    Solution solution; 
    cout << solution.differenceOfSums(10, 3) << endl; // 19
}