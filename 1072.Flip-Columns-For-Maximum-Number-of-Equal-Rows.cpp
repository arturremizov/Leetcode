#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        for (auto row : matrix) {
            string key = vectorToString(row);
            if (row[0] == 1) {
                vector<int> invertedRow = row;
                for (int i = 0; i < row.size(); ++i) {
                    invertedRow[i] = invertedRow[i] == 1 ? 0 : 1;
                }
                key = vectorToString(invertedRow);
            }
            count[key]++;
        }

        int result = 0;
        for (auto [_, value] : count) {
            result = max(result, value);
        } 
        return result;
    }
private: 
    string vectorToString(const vector<int>& vector) {
        string result;
        for (int num : vector) {
            result += to_string(num);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {0,0,0},
        {0,0,1},
        {1,1,0}
    };
    cout << solution.maxEqualRowsAfterFlips(matrix) << endl; // 2
}