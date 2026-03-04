#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int rows = mat.size(), cols = mat[0].size();
        vector<int> rowCount(rows), colCount(cols);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) { 
                if (mat[row][col] == 1 && rowCount[row] == 1 && colCount[col] == 1) {
                    ++result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> mat = {
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };
    cout << solution.numSpecial(mat) << endl; // 1
}