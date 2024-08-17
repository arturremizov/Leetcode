#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int rows = points.size(), cols = points[0].size();

        vector<long long> prevRow(points[0].begin(), points[0].end());
        for (int row = 1; row < rows; ++row) {
            vector<long long> nextRow(points[row].begin(), points[row].end());
            vector<long long> left(cols), right(cols);
            
            left[0] = prevRow[0];
            for (int col = 1; col < cols; ++col) {
                left[col] = max(prevRow[col], left[col - 1] - 1);
            }

            right[cols - 1] = prevRow[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                right[col] = max(prevRow[col], right[col + 1] - 1);
            }

            for (int col = 0; col < cols; ++col) {
                nextRow[col] += max(left[col], right[col]);
            }
            prevRow = nextRow;
        }
        return *max_element(prevRow.begin(), prevRow.end());
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> points = {{1,2,3}, {1,5,1}, {3,1,1}};
    cout << solution.maxPoints(points) << endl; // 9
}