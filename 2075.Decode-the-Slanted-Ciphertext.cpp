#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));
        int i = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                grid[row][col] = encodedText[i];
                ++i;
            }
        }

        string result;
        for (int col = 0; col < cols; ++col) {
            for (int i = 0; i < rows; ++i) {
                if (col + i == cols) break;
                result += grid[i][col + i];
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.decodeCiphertext("iveo    eed   l te   olc", 4) << endl; //i love leetcode
}