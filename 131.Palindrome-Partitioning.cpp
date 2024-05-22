#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        dfs(s, 0, partition, result);
        return result;
    }
private: 
    void dfs(string &s, int i, vector<string> &partition, vector<vector<string>>& result) {
        if (i == s.length()) {
            result.push_back(partition);
            return;
        }
        for (int j = i; j < s.length(); ++j) {
            if (isPalindrom(s, i, j)) {
                partition.push_back(s.substr(i, j + 1 - i));
                dfs(s, j + 1, partition, result);
                partition.pop_back();
            }
        }
    }
    bool isPalindrom(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<string>> result = solution.partition("aab"); // [["a","a","b"],["aa","b"]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "] ";
    }
}