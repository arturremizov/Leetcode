#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int n = ring.length();
        const int k = key.length();
        vector<int> dp(n);
        for (int i = k - 1; i >= 0; --i) {
            vector<int> next_dp(n, INT_MAX);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (ring[k] == key[i]) {
                        int minDist = min(abs(j - k), n - abs(j - k));
                        next_dp[j] = min(next_dp[j], minDist + 1 + dp[k]);
                    }
                }
            }
            dp = next_dp;
        }
        return dp[0];
    }
};

int main() 
{
    Solution solution; 
    cout << solution.findRotateSteps("godding", "gd") << endl; // 4
    cout << solution.findRotateSteps("godding", "godding") << endl; // 13
}