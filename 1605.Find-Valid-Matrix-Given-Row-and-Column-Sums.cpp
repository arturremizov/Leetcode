#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int rows = rowSum.size(), cols = colSum.size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; ++row) { 
            for (int col = 0; col < cols; ++col) {
                int value = min(rowSum[row], colSum[col]);
                result[row][col] = value;
                rowSum[row] -= value;
                colSum[col] -= value;
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> rowSum = {3,8};
    vector<int> colSum = {4,7};
    vector<vector<int>> result = solution.restoreMatrix(rowSum, colSum);
    cout << "[";
    for (int row = 0; row < result.size(); ++row) { 
        cout << "[";
        for (int col = 0; col < result[0].size(); ++col) {
            cout << result[row][col];
            if (col < result[0].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (row < result.size() - 1) {
            cout << ",\n";
        }
    }
    cout << "]\n";
}