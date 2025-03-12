#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        const int n = blocks.size();
        int whiteCount = 0;
        int result = n;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (blocks[right] == 'W') {
                ++whiteCount;
            }
            if (right - left + 1 == k) {
                result = min(result, whiteCount);
                if (blocks[left] == 'W') {
                    --whiteCount;
                }
                ++left;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minimumRecolors("WBBWWBBWBW", 7) << endl; // 3
}