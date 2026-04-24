#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, empty = 0;
        for (char c : moves) {
            if (c == 'L') {
                ++left;
            } else if (c == 'R') {
                ++right;
            } else {
                ++empty;
            }
        }
        return max(left - right, right - left) + empty;
    }
};

int main() {
    Solution solution;
    cout << solution.furthestDistanceFromOrigin("_R__LL_") << endl; // 5
}
