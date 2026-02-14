#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prevRow = { double(poured) };
        for (int row = 1; row < query_row + 1; ++row) {
            vector<double> curRow(row + 1);
            for (int i = 0; i < row; ++i) {
                double extra = prevRow[i] - 1;
                if (extra > 0) {
                    curRow[i] += 0.5 * extra;
                    curRow[i + 1] += 0.5 * extra;
                }
            }
            prevRow = curRow;
        }
        return min(1.0, prevRow[query_glass]);
    }
};


int main() {
    Solution solution; 
    cout << solution.champagneTower(2,1,1) << endl; // 0.50000
}