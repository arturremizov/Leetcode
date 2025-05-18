#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> states = generateValidColumnStates(m);
        // col index : [compatible col indices]
        vector<vector<int>> compatible = computeCompatibility(states, m);

        return countColorings(n, states.size(), compatible);
    }
private:
    vector<vector<int>> generateValidColumnStates(int m) {
        vector<vector<int>> validStates;
        vector<int> curState;
        dfs(0, validStates, curState, m);
        return validStates;
    }
    void dfs(int row, vector<vector<int>>& validStates, vector<int>& state, int m) {
        if (row == m) {
            validStates.push_back(state);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (row == 0 || state[row - 1] != color) {
                state.push_back(color);
                dfs(row + 1, validStates, state, m);
                state.pop_back();
            }
        }
    }
    vector<vector<int>> computeCompatibility(vector<vector<int>>& states, int m) {
        int k = states.size();
        vector<vector<int>> compatible(k);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                bool isCompatible = true;
                for (int row = 0; row < m; ++row) {
                    if (states[i][row] == states[j][row]) {
                        isCompatible = false;
                        break;
                    }
                }
                if (isCompatible) {
                    compatible[i].push_back(j);
                }
            } 
        }
        return compatible;
    }
    int countColorings(int n, int k, vector<vector<int>>& compatible) {
        const int MOD = 1e9+7;
        vector<int> dp(k, 1);
        for (int col = 1; col < n; ++col) {
            vector<int> newDp(k);
            for (int i = 0; i < k; ++i) {
                for (int j : compatible[i]) {
                    newDp[i] = (newDp[i] + dp[j]) % MOD;
                }
            }
            dp = newDp;
        }

        int result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.colorTheGrid(5, 5) << endl; // 580986
}
 