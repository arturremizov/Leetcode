#include <iostream>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int result = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 > num2) {
                result += num1 / num2;
                num1 = num1 % num2;
            } else {
                result += num2 / num1;
                num2 = num2 % num1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countOperations(2, 3) << endl; // 3
}