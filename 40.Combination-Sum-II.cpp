#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, {}, 0, target, result);
        return result;
    }
private:
    void backtrack(vector<int>& candidates, int i, vector<int> current, int total, int target, vector<vector<int>>& result) {
        if (total > target || i == candidates.size()) return;

        if (total == target) {
            result.push_back(current);
            return;
        }

        // include candidates[i]
        current.push_back(candidates[i]);
        backtrack(candidates, i + 1, current, total + candidates[i], target, result);
        current.pop_back();

        // skip candidates[i]
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
           ++i;
        }
        backtrack(candidates, i + 1, current, total, target, result);
    }
};

int main() 
{
    Solution solution; 
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> result = solution.combinationSum2(candidates, 8);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}