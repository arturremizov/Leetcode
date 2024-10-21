#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> currentSet;
        return backtrack(s, 0, currentSet);
    }
private:
    int backtrack(string& s, int i, unordered_set<string>& currentSet) {
        if (i == s.length()) return 0;
        int result = 0;
        for (int j = i; j < s.length(); ++j) {
            string substring = s.substr(i, (j + 1) - i);
            if (currentSet.count(substring)) continue;
            currentSet.insert(substring);
            result = max(result, 1 + backtrack(s, j + 1, currentSet));
            currentSet.erase(substring);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxUniqueSplit("ababccc") << endl; // 5
}