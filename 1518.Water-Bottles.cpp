#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;
        int empty = 0;
        while (numBottles > 0) {
            result += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.numWaterBottles(9, 3) << endl; // 13
    cout << solution.numWaterBottles(15, 4) << endl; // 19
}