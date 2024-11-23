#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int rows = box.size(), cols = box[0].size();
        for (int row = 0; row < rows; ++row) {
            int i = cols - 1;
            for (int col = cols - 1; col >= 0; --col) {
                if (box[row][col] == '#') {
                    swap(box[row][col], box[row][i]);
                    --i;
                } else if (box[row][col] == '*') {
                    i = col - 1;
                }
            }
        }
        vector<vector<char>> result;
        for (int col = 0; col < cols; ++col) {
            vector<char> column;
            for (int row = rows - 1; row >= 0; --row) {
                column.push_back(box[row][col]);
            }
            result.push_back(column);
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