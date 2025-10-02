#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            ++numBottles;
            ++result;
            ++numExchange;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxBottlesDrunk(13, 6) << endl; // 15
}