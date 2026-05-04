#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int top = left, bottom = right;
            for (int i = 0; i < right - left; ++i) {
                int topLeft = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = topLeft;
            }
            ++left, --right;
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    solution.rotate(matrix);

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