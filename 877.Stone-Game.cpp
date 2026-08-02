#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> memo = vector(n, vector(n, INT_MIN));
        int difference = dfs(0, n - 1, piles, memo);
        return difference > 0;
    }
private:
    int dfs(int left, int right, vector<int>& piles, vector<vector<int>>& memo) {
        if (left == right) return piles[left];
        if (memo[left][right] != INT_MIN) return memo[left][right];
        int takeLeft = piles[left] - dfs(left + 1, right, piles, memo);
        int takeRight = piles[right] - dfs(left, right - 1, piles, memo);
        return memo[left][right] = max(takeLeft, takeRight);
    }
};

int main() {
    Solution solution; 
    vector<int> piles = {5,3,4,5};
    cout << solution.stoneGame(piles) << endl; // true
}