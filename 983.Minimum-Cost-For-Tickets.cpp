#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<pair<int, int>> costsForDays {
            {costs[0], 1}, {costs[1], 7}, {costs[2], 30}
        };

        unordered_map<int, int> memo;
        return dfs(0, days, costsForDays, memo);
    }
private:
    int dfs(int i, vector<int>& days, vector<pair<int, int>>& costsForDays,
            unordered_map<int, int>& memo) {
        if (memo.count(i)) return memo[i];
        if (i == days.size()) return 0;
        
        int result = INT32_MAX;
        int j = i;
        for (auto [cost, duration] : costsForDays) {
            while (j < days.size() && days[j] < days[i] + duration) {
                ++j;
            }
            result = min(result, cost + dfs(j, days, costsForDays, memo));
        }
        memo[i] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout << solution.mincostTickets(days, costs) << endl; // 11
}