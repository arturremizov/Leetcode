#include <iostream>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(z - x) == abs(z - y)) return 0;
        return abs(z - x) < abs(z - y) ? 1 : 2;
    }
};

int main() {
    Solution solution; 
    cout << solution.findClosest(2,7,4) << endl; // 1
}