#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int n = grid.size();
        unordered_set<int> visited;
        int repeatingNum;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited.count(grid[i][j])) {
                    repeatingNum = grid[i][j];
                } else {
                    visited.insert(grid[i][j]);
                }
            }
        }
        for (int i = 1; i <= n * n; ++i) {
            if (!visited.count(i)) {
                return {repeatingNum, i};
            }
        }
        return {};
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {{1,3}, {2,2}};
    vector<int> result = solution.findMissingAndRepeatedValues(grid); // [2,4]
    cout << "[" << result[0] << "," << result[1] << "]\n";
}