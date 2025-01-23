#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();

        vector<int> serverRowCount(rows), serverColCount(cols);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    serverRowCount[row]++;
                    serverColCount[col]++;
                }
            }
        }
        
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1 && 
                    (serverRowCount[row] > 1 || serverColCount[col] > 1)) {
                    ++result;
                }
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {1,0},
        {1,1}
    };
    cout << solution.countServers(grid) << endl; // 3
}