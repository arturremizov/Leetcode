#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<string, vector<char>> bottomToTop;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& str : allowed) {
            bottomToTop[str.substr(0, 2)].push_back(str[2]);
        }
        return dfs(bottom);
    }
private:
    unordered_set<string> badRows; 

    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (badRows.count(row)) return false;

        string next;
        if (buildNextRow(row, 0, next)) return true;

        badRows.insert(row);
        return false;
    }

    bool buildNextRow(const string& row, int i, string& nextRow) {
        if (i == row.size() - 1) return dfs(nextRow);
        
        string key = {row[i], row[i + 1]};
        if (!bottomToTop.count(key)) return false;

        for (char c : bottomToTop[key]) {
            nextRow.push_back(c);
            if (buildNextRow(row, i + 1, nextRow)) return true;
            nextRow.pop_back();
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<string> allowed = {"CBB","ACB","ABD","CDB","BDC","CBC","DBA","DBB","CAB","BCB","BCC","BAA","CCD","BDD","DDD","CCA","CAA","CCC","CCB"};
    cout << solution.pyramidTransition("CCC",allowed) << endl; // true
}