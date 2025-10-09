#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        const int n = skill.size(), m = mana.size();
        vector<long long> dp(n);
        for (int j = 0; j < m; ++j) {
            long long currTime = 0;
            for (int i = 0; i < n; ++i) {
                currTime = max(currTime, dp[i]) + skill[i] * mana[j];
            }
            dp[n - 1] = currTime;
            for (int i = n - 2; i >= 0; --i) {
                dp[i] = dp[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution solution; 
    vector<int> skill = {1,5,2,4};
    vector<int> mana = {5,1,4,2};
    cout << solution.minTime(skill,mana) << endl; // 110
    
}