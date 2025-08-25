#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int rows = mat.size(), cols = mat[0].size();
        vector<int> result;
        int row = 0, col = 0;
        bool isGoingUp = true;
        while (row < rows && col < cols) {
            result.push_back(mat[row][col]);
            if (isGoingUp) {
                if (row == 0 || col == cols - 1) {
                    isGoingUp = false;
                    if (row == 0 && col < cols - 1) {
                        ++col;
                    } else {
                        ++row;
                    }
                } else {
                    --row, ++col;
                }
            } else {
                if (row == rows - 1 || col == 0) {
                    isGoingUp = true;
                    if (col == 0 && row < rows - 1) {
                        ++row;
                    } else {
                        ++col;
                    }
                } else {
                    ++row, --col;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> result = solution.findDiagonalOrder(mat); // [1,2,4,7,5,3,6,8,9]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}