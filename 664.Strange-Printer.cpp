#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        unordered_map<string, int> memo;
        return helper(s, 0, s.length() - 1, memo);
    }
private:
    int helper(string& s, int left, int right, unordered_map<string, int>& memo) {
        string key = to_string(left) + "," + to_string(right);
        if (memo.count(key)) return memo[key];

        if (left > right) return 0;
        if (left == right) return 1;
        // print only first char
        int result = 1 + helper(s, left + 1, right, memo);

        for (int i = left + 1; i <= right; ++i) {
            if (s[left] == s[i]) {
                result = min(
                    result,
                    helper(s, left + 1, i - 1, memo) + helper(s, i, right, memo)
                );
            }
        }
        memo[key] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.strangePrinter("aaabbb") << endl; // 2
    cout << solution.strangePrinter("aba") << endl; // 2
}