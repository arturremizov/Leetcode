#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remainingDays = n % 7;
        int result = 0;
        int curWeek = 28;
        for (int i = 0; i < weeks; ++i) {
            result += curWeek;
            curWeek += 7;
        }
        for (int i = 1; i <= remainingDays; ++i) {
            result += (weeks + i);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.totalMoney(20) << endl; // 96
}