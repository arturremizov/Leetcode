#include <iostream>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count1 = countBits(num1);
        int count2 = countBits(num2);

        int result = num1;
        int i = 0;
        while (count1 > count2) {
            if (result & (1 << i)) {
                --count1;
                result = result ^ (1 << i);
            }
            ++i;
        }

        while (count1 < count2) {
            if ((result & (1 << i)) == 0) {
                ++count1;
                result = result | (1 << i);
            }
            ++i;
        }
        return result;
    }
private:
    int countBits(int num) {
        int result = 0;
        while (num > 0) {
            result += (num & 1);
            num = num >> 1;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minimizeXor(1, 12) << endl; // 3
}