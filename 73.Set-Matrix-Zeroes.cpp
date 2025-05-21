#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        bool rowZero = false;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    if (row == 0) {
                        rowZero = true;
                    } else {
                        matrix[row][0] = 0;
                    }
                    matrix[0][col] = 0;
                }
            }
        }
        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (matrix[0][col] == 0 || matrix[row][0] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }

        if (rowZero) {
            for (int col = 0; col < cols; ++col) {
                matrix[0][col] = 0;
            }
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    solution.setZeroes(matrix); //  [[1,0,1],[0,0,0],[1,0,1]]
    for (int i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}
