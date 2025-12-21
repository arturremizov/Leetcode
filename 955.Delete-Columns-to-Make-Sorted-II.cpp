#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n = strs.size(), m = strs[0].size();
        vector<bool> rowSorted(n);
        int result = 0;
        for (int col = 0; col < m; ++col) {
            bool isValid = true;

            for (int row = 1; row < n; ++row) {
                if (!rowSorted[row] && strs[row - 1][col] > strs[row][col]) {
                    isValid = false;
                    break;
                } 
            }

            if (!isValid) {
                ++result;
                continue;
            }

            for (int row = 1; row < n; ++row) {
                if (!rowSorted[row] && strs[row - 1][col] < strs[row][col]) {
                    rowSorted[row] = true;
                } 
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> strs = {"xga","xfb","yfa"};
    cout << solution.minDeletionSize(strs) << endl; // 1
}