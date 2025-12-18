#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        const int n = prices.size();
        vector<long long> profit(n + 1);
        vector<long long> sellSum(n + 1);
        for (int i = 0; i < n; ++i) {
            profit[i + 1] = profit[i] + prices[i] * strategy[i];
            sellSum[i + 1] = sellSum[i] + prices[i];
        }

        long long result = profit[n];
        for (int i = k - 1; i< n; ++i) {
            long long leftProfit = profit[i - k + 1];
            long long rightProfit = profit[n] - profit[i + 1];
            long long additionalProfit = sellSum[i + 1] - sellSum[i + 1 - k / 2];
            result = max(result, leftProfit + rightProfit + additionalProfit);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> prices = {4,2,8};
    vector<int> strategy = {-1,0,1};
    cout << solution.maxProfit(prices, strategy, 2) << endl; // 10
}