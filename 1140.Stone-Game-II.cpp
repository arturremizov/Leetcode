#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        unordered_map<string, int> memo;
        return numberOfStonesAliceGet(piles, 0, 1, true, memo);
    }
private:
    int numberOfStonesAliceGet(vector<int>& piles, int i, int m, bool isAliceTurn, unordered_map<string, int>& memo) {
        string key = to_string(i) + "," + to_string(m) + "," + to_string(isAliceTurn);
        if (memo.count(key)) return memo[key];

        if (i == piles.size()) return 0;

        int result = isAliceTurn ? 0 : INT_MAX;
        int total = 0;
        for (int x = 1; x <= m * 2; ++x) {
            if (i + x > piles.size()) break;
            total += piles[i + x - 1];

            if (isAliceTurn) {
                result = max(result, total + numberOfStonesAliceGet(piles, i + x, max(m, x), !isAliceTurn, memo));
            } else {
                result = min(result, numberOfStonesAliceGet(piles, i + x, max(m, x), !isAliceTurn, memo));
            }
        }
        memo[key] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> piles = {2,7,9,4,4};
    cout << solution.stoneGameII(piles) << endl; // 10
}