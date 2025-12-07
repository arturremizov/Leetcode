#include <iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == 0) ++low; 
        int result = 0;
        for (int num = low; num <= high; num += 2) {
            ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countOdds(3, 7) << endl; // 3
}