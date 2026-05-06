#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int n = box.size(), m = box[0].size();
        vector result = vector(m, vector(n, '.'));
        for (int row = 0; row < n; ++row) {
            int rotatedRow = m - 1;
            const int rotatedCol = n - row - 1; 
            for (int col = m - 1; col >= 0; --col) {
                if (box[row][col] == '#') {
                    result[rotatedRow][rotatedCol] = '#';
                    --rotatedRow;
                } else if (box[row][col] == '*') {
                    result[col][rotatedCol] = '*';
                    rotatedRow = col - 1;
                }
            }
        }
        return result;     
    }
};

int main() {
    Solution solution; 
    vector<vector<char>> box = {{'#','.', '#'}};
    vector<vector<char>> result = solution.rotateTheBox(box); // [["."],["#"], ["#"]]
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