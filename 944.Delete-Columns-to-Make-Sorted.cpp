#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int rows = strs.size(), cols = strs[0].size();
        int result = 0;
        for (int col = 0; col < cols; ++col) {
            for (int row = 1; row < rows; ++row) {
                if (strs[row - 1][col] > strs[row][col]) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> strs = {"cba","daf","ghi"};
    cout << solution.minDeletionSize(strs) << endl; // 1
}