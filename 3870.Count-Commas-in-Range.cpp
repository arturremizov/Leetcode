#include <iostream>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        return max(n - 1000 + 1, 0);
    }
};

int main() {
    Solution solution; 
    cout << solution.countCommas(1002) << endl; // 3
}