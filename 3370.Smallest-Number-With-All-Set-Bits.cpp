#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int num = 0;
        for (int i = 0; i < 32; ++i) {
            num |= 1 << i;
            if (num >= n) break; 
        }
        return num;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestNumber(5) << endl; // 7
}