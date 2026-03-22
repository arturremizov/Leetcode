#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int n = mat.size();
        for (int i = 0; i < 4; ++i) {
            vector<vector<int>> newMatrix(n, vector<int>(n));
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < n; ++col) {
                    newMatrix[col][n - row - 1] = mat[row][col];
                }
            }
            if (newMatrix == target) return true;
            mat = newMatrix;
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    vector<vector<int>> target = {
        {1,1,1},
        {0,1,0},
        {0,0,0}
    };
    cout << solution.findRotation(mat,target) << endl; // true
}