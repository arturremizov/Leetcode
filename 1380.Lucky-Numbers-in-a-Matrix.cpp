#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int maxOfRowMins = INT_MIN;
        for (int row = 0; row < rows; ++row) {
            int rowMin = *min_element(matrix[row].begin(), matrix[row].end());
            maxOfRowMins = max(rowMin, maxOfRowMins);
        }

        for (int col = 0; col < cols; ++col) { 
            int colMax = INT_MIN;
            for (int row = 0; row < rows; ++row) {
                colMax = max(colMax, matrix[row][col]);
            }
            if (colMax == maxOfRowMins) {
                return {colMax};
            }
        }
        return {};
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> result = solution.luckyNumbers(matrix); // [15]
    for (int num : result) { 
        cout << num << "\n";
    }
}