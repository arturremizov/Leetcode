#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int rows = mat.size(), cols = mat[0].size();
        int shifts = k % cols;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row % 2 == 0) {
                    if (mat[row][col] != mat[row][(col + shifts) % cols]) {
                        return false;
                    }
                } else {
                    if (mat[row][col] != mat[row][(col - shifts + cols) % cols]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << solution.areSimilar(mat, 4) << endl; // false
}