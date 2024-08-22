#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        while (mask < num) {
            mask = (mask << 1) | 1;
        }
        return num ^ mask;
    }
};

int main() {
    Solution solution; 
    cout << solution.findComplement(5) << endl; // 2
    cout << solution.findComplement(1) << endl; // 0
}