#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for (int i = low; i <= high; ++i) {
            if (isSymmetric(i)) {
                ++result;
            }
        }
        return result;
    }
private:
    bool isSymmetric(int num) {
        string s = to_string(num);
        int length = s.length();
        if (length % 2 == 1) return false;
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < length; ++i) {
            if (i < length / 2) {
                leftSum += s[i] - '0';
            } else {
                rightSum += s[i] - '0';
            }
        }
        return leftSum == rightSum;
    }
};

int main() {
    Solution solution; 
    cout << solution.countSymmetricIntegers(1, 100) << endl; // 9
}