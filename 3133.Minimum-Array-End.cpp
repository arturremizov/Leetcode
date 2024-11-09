#include <iostream>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        for (int i = 1; i < n; ++i) {
            result += 1;
            result = result | x;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minEnd(3, 4) << endl; // 6
}