#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        int result = 0;
        vector<int> prewHeights(cols);
        for (int row = 0; row < rows; ++row) {
            vector<int> heights = matrix[row];
            for (int col = 0; col < cols; ++col) {
                if (heights[col] > 0) {
                    heights[col] += prewHeights[col];
                }
            }

            vector<int> sortedHeights = heights;
            sort(sortedHeights.begin(), sortedHeights.end(), greater());
            for (int col = 0; col < cols; ++col) {
                result = max(result, (col + 1) * sortedHeights[col]);
            }
            prewHeights = heights;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {0,0,1},
        {1,1,1},
        {1,0,1}
    };
    cout << solution.largestSubmatrix(matrix) << endl; // 4
}