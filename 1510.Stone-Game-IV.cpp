#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }
        vector<int> memo(n + 1, -1);
        return dfs(n, squares, memo);
    }
private:
    bool dfs(int stones, const vector<int>& squares, vector<int>& memo) {
        if (stones == 0) return false;
        if (memo[stones] != -1) return memo[stones];
        bool result = false;
        for (int square : squares) {
            if (square > stones) break;
            if (!dfs(stones - square, squares, memo)) {
                result = true;
                break;
            }
        }
        return memo[stones] = result;
    }
};

int main() {
    Solution solution; 
    cout << solution.winnerSquareGame(99) << endl; // true
}