#include <iostream>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1;
        for (int i = 0; i < n; ++i) {
            result += (4 * i);
        } 
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.coloredCells(2) << endl; // 5
}