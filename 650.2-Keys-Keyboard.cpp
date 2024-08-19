#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        return 1 + helper(n, 1, 1);
    }
private: 
    int helper(int n, int length, int paste) {
        if (length == n) return 0;
        if (length > n) return 1000;
        int result = min(
            // paste 
            1 + helper(n, length + paste, paste),
            // copy and paste
            2 + helper(n, length + length, length)
        );
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minSteps(3) << endl; // 3
}