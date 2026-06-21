#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int minCost = *min_element(costs.begin(), costs.end());
        const int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> count(maxCost + 1);
        for (int cost : costs) {
            count[cost]++;
        }
        int barsBought = 0;
        for (int cost = minCost; cost <= maxCost; ++cost) {
            if (count[cost] == 0) continue;
            long long barsCost = 1LL * cost * count[cost]; 
            if (coins >= barsCost) {
                barsBought += count[cost];
                coins -= barsCost;
            } else {
                if (coins < cost) break;
                int ableToBuyBars = coins / cost;
                barsBought += ableToBuyBars;
                coins -= ableToBuyBars * cost;
            }
        }
        return barsBought;
    }
};

int main() {
    Solution solution; 
    vector<int> costs = {4,7,6,4,4,2,2,4,8,8};
    cout << solution.maxIceCream(costs, 41) << endl; // 9
}