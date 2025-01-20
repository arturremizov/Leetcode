#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rows = mat.size(), cols = mat[0].size();

        unordered_map<int, pair<int, int>> integerPosition;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                integerPosition[mat[row][col]] = {row, col};
            } 
        }

        vector<int> rowCount(rows), colCount(cols);
        for (int i = 0; i < arr.size(); ++i) {
            auto [row, col] = integerPosition[arr[i]];
            rowCount[row]++;
            colCount[col]++;
            if (rowCount[row] == cols || colCount[col] == rows) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {
        {1,4},
        {2,3}
    }; 
    cout << solution.firstCompleteIndex(arr, mat) << endl; // 2
}