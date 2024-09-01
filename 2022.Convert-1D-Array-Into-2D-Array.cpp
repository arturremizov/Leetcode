#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> result(m, vector<int>(n));
        int index = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                result[row][col] = original[index];
                ++index;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> original = {1,2,3,4};
    vector<vector<int>> result = solution.construct2DArray(original, 2, 2);
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