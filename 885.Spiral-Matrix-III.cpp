#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        vector<vector<int>> result;
        int row = rStart, col = cStart;
        int steps = 1;
        int i = 0;
        while (result.size() < rows * cols) {
            
            for (int j = 0; j < 2; j++) {
                auto direction = directions[i];
                for (int k = 0; k < steps; k++) {
                    if (row >= 0 && col >= 0 && row < rows && col < cols) {
                        result.push_back({row, col});
                    }
                    row += direction.first;
                    col += direction.second;
                }

                i = (i + 1) % 4;
            }
            ++steps;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> result = solution.spiralMatrixIII(1,4,0,0); // [[0,0],[0,1],[0,2],[0,3]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i < result.size() - 1) cout << ",";
    }
}