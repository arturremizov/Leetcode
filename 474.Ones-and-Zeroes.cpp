#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<string, int> memo;
        return dfs(0, m, n, strs, memo);
    }
private:
    int dfs(int i, int m, int n, vector<string>& strs, unordered_map<string, int>& memo) {
        if (i == strs.size()) return 0;
        string key = to_string(i) + "," + to_string(m) + "," + to_string(n);
        if (memo.count(key)) return memo[key];

        int result = dfs(i + 1, m, n, strs, memo); // skip

        auto [zeros, ones] = countZerosAndOnes(strs[i]);
        if (m >= zeros && n >= ones) {
            int includeResult = 1 + dfs(i + 1, m - zeros, n - ones, strs, memo); // include
            result = max(result, includeResult);
        }
        memo[key] = result;
        return result;
    }
    pair<int, int> countZerosAndOnes(string str) {
        int zeros = 0, ones = 0;
        for (char c : str) {
            if (c == '0') {
                ++zeros;
            } else if (c == '1') {
                ++ones;
            }
        }
        return {zeros, ones};
    }
};

int main() {
    Solution solution; 
    vector<string> strs = {"10","0001","111001","1","0"};
    cout << solution.findMaxForm(strs, 5, 3) << endl; // 4
}