#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diffMatrix(n + 1, vector<int>(n + 1));
        for (auto& query : queries) {
            int startRow = query[0], startCol = query[1];
            int endRow = query[2], endCol = query[3];

            diffMatrix[startRow][startCol] += 1;
            diffMatrix[startRow][endCol + 1] -= 1;
            diffMatrix[endRow + 1][startCol] -= 1;
            diffMatrix[endRow + 1][endCol + 1] += 1;
        }

        vector<vector<int>> matrix(n, vector<int>(n));
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int top = row == 0 ? 0 : matrix[row - 1][col];
                int left = col == 0 ? 0 : matrix[row][col - 1];
                int topLeft = row == 0 || col == 0 ? 0 : matrix[row - 1][col - 1];
                matrix[row][col] = diffMatrix[row][col] + top + left - topLeft;
            }
        }
        return matrix;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> queries = {{1,1,2,2},{0,0,1,1}};
    vector<vector<int>> result = solution.rangeAddQueries(3, queries);
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