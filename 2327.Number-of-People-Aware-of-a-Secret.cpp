#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        queue<pair<int, int>> discoveredQueue; // day, count
        queue<pair<int, int>> sharedQueue; // day, count
        discoveredQueue.push({1, 1}); 
        int discoveredTotal = 1, sharedTotal = 0;
        for (int currentDay = 2; currentDay <= n; ++currentDay) {
            if (discoveredQueue.front().first + delay == currentDay) {
                auto [day, count] = discoveredQueue.front();
                discoveredQueue.pop();
                discoveredTotal = (discoveredTotal - count + MOD) % MOD;
                sharedQueue.push({day, count});
                sharedTotal = (sharedTotal + count) % MOD;
            }   
            if (sharedQueue.front().first + forget == currentDay) {
                auto [day, count] = sharedQueue.front();
                sharedQueue.pop();
                sharedTotal = (sharedTotal - count + MOD) % MOD;
            }
            if (!sharedQueue.empty()) {
                discoveredQueue.push({currentDay, sharedTotal});
                discoveredTotal = (discoveredTotal + sharedTotal) % MOD;
            }
        }
        return (discoveredTotal + sharedTotal) % MOD;
    }
};

int main() {
    Solution solution; 
    cout << solution.peopleAwareOfSecret(6, 2, 4) << endl; // 5
}
