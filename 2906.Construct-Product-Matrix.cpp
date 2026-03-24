#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        const int rows = grid.size(), cols = grid[0].size();
        const int total = rows * cols;

        vector<long long> flat;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                flat.push_back(grid[row][col]);
            }
        }

        vector<long long> prefix(total, 1);
        for (int i = 1; i < total; ++i) {
            prefix[i] = (prefix[i - 1] * flat[i - 1]) % MOD;
        }

        vector<long long> suffix(total, 1);
        for (int i = total - 2; i >= 0; --i) {
            suffix[i] = (suffix[i + 1] * flat[i + 1]) % MOD;
        }

        vector<vector<int>> result(rows, vector<int>(cols));
        for (int i = 0; i < total; ++i) { 
            result[i / cols][i % cols] = prefix[i] * suffix[i] % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2},
        {3,4}
    };
    vector<vector<int>> result = solution.constructProductMatrix(grid); //[[24,12],[8,6]]
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