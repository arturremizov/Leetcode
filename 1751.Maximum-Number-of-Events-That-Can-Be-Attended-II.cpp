#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int n = events.size();
        sort(events.begin(), events.end());
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = events[i][0];
        }
        vector<vector<int>> memo(k + 1, vector<int>(n, -1));
        return dfs(events, starts, 0, k, memo);
    }
private:
    int dfs(vector<vector<int>>& events, vector<int>& starts, int currentIndex, int count, vector<vector<int>>& memo) {
        if (count == 0 || currentIndex == events.size()) {
            return 0;
        }
        if (memo[count][currentIndex] != -1) {
            return memo[count][currentIndex];
        }
       
        int skipResult = dfs(events, starts, currentIndex + 1, count, memo); 

        auto it = upper_bound(starts.begin(), starts.end(), events[currentIndex][1]);
        int nextIndex = distance(starts.begin(), it);
        int includeResult = events[currentIndex][2] + dfs(events, starts, nextIndex, count - 1, memo);
        memo[count][currentIndex] = max(skipResult, includeResult);
        return memo[count][currentIndex];
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> events = {{1,2,4}, {3,4,3}, {2,3,1}};
    cout << solution.maxValue(events, 2) << endl; // 7
}