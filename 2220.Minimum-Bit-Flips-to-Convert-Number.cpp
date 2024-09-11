#include <iostream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;
        int result = 0;
        while (num > 0) {
            // result += num & 1;
            // num = num >> 1;

            // Brian Kernighan's Algorithm
            num = num & (num - 1);
            ++result;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.minBitFlips(10, 7) << endl; // 3
    cout << solution.minBitFlips(3, 4) << endl; // 3
}