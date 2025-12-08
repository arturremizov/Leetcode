#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        for (int a = 1; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                int c = sqrt(a * a + b * b);
                if (c <= n && c * c == (a * a + b * b)) {
                    result += 2;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countTriples(10) << endl; // 4
}