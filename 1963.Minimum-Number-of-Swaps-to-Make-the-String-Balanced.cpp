#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int closeCount = 0;
        int maxCloseCount = 0;
        for (char c : s) {
            if (c == '[') {
                --closeCount;
            } else {
                ++closeCount;
            }
            maxCloseCount = max(maxCloseCount, closeCount);
        }
        return (maxCloseCount + 1) / 2;
    }
};

int main() {
    Solution solution; 
    cout << solution.minSwaps("][][") << endl; // 1
}