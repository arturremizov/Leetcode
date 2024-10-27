#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        unordered_map<string, int> cache;
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                result += dfs(matrix, row, col, cache);
            }
        }
        return result;
    }
private:
    int dfs(vector<vector<int>>& matrix, int row, int col, unordered_map<string, int>& cache) {
        string key = to_string(row) + "," + to_string(col);
        if (cache.count(key)) return cache[key];

        const int rows = matrix.size(), cols = matrix[0].size();
        if (row == rows || col == cols || matrix[row][col] == 0) {
            return 0;
        }

        int lenght = 1 + min(
            dfs(matrix, row + 1, col, cache),
            min(dfs(matrix, row, col + 1, cache),
                dfs(matrix, row + 1, col + 1, cache))
        );
        cache[key] = lenght;
        return lenght;
     }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << solution.countSquares(matrix) << endl; // 15
}