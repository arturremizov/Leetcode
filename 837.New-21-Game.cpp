#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        double windowSum = 0;
        for (int i = k; i < k + maxPts; ++i) {
            if (i <= n) ++windowSum;
        }
        unordered_map<int, double> dp;
        for (int i = k - 1; i >= 0; --i) {
            dp[i] = windowSum / maxPts;

            double removeValue = 0;
            if (i + maxPts <= n) {
                if (dp.count(i + maxPts)) {
                    removeValue = dp[i + maxPts];
                } else {
                    removeValue = 1;
                }
            }
            windowSum += dp[i] - removeValue;
        }
        return dp[0];
    }
};

int main() {
    Solution solution; 
    cout << solution.new21Game(10,1,10) << endl; // 1.00000
}