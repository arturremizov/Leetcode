#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> powerMap;
        for (int p : power) powerMap[p]++; 
        vector<pair<int, int>> powerCount(powerMap.begin(), powerMap.end());
        vector<long long> memo(powerCount.size(), -1);
        return dfs(0, powerCount, memo);
    }
private:
    long long dfs(int i, vector<pair<int, int>>& powerCount, vector<long long>& memo) {
        const int n = powerCount.size();
        if (i == n) return 0;
        if (memo[i] != -1) return memo[i];
        // skip
        long long skipResult = dfs(i + 1, powerCount, memo); 
        // include
        int j = i + 1;
        while (j < n && powerCount[j].first <= powerCount[i].first + 2) {
            ++j;
        }
        long long damage = 1LL * powerCount[i].first * powerCount[i].second;
        long long includeResult = damage + dfs(j, powerCount, memo);
        memo[i] = max(skipResult, includeResult);
        return memo[i];
    }
};

int main() {
    Solution solution; 
    vector<int> power = {1,1,3,4};
    cout << solution.maximumTotalDamage(power) << endl; // 6
}