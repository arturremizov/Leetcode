#include <iostream>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRounds = time / (n - 1);
        int extraTime = time % (n - 1);
        if (fullRounds % 2 == 0) { 
            return extraTime + 1;
        } else {                  
            return n - extraTime;
        }
    }
};

int main() 
{
    Solution solution; 
    cout << solution.passThePillow(4, 5) << endl; // 2
    cout << solution.passThePillow(3, 2) << endl; // 3
}