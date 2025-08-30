#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<vector<unordered_set<int>>> squares(3, vector<unordered_set<int>>(3));
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') continue;
                int digit = board[row][col] - '0';
                if (rows[row].count(digit)) return false;
                if (cols[col].count(digit)) return false;
                if (squares[row / 3][col / 3].count(digit)) return false;
                rows[row].insert(digit);
                cols[col].insert(digit);
                squares[row / 3][col / 3].insert(digit);
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << solution.isValidSudoku(board) << endl; // true
}