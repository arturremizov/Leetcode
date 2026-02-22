#include <iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        int i = 0;
        int prev = -1;
        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    result = max(result, i - prev);
                }
                prev = i;
            }
            n >>= 1;
            ++i;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.binaryGap(22) << endl; // 2
}