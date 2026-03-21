#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int topRow = x;
        int bottomRow = x + k - 1;
        while (topRow < bottomRow) {
            for (int col = y; col < y + k; ++col) {
                swap(grid[topRow][col], grid[bottomRow][col]);
            }
            ++topRow, --bottomRow;
        }
        return grid;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>> result = solution.reverseSubmatrix(grid, 1,0,3); // [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]
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