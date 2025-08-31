#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<vector<unordered_set<int>>> squares(3, vector<unordered_set<int>>(3));
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') continue;
                int digit = board[row][col] - '0';
                rows[row].insert(digit);
                cols[col].insert(digit);
                squares[row / 3][col / 3].insert(digit);
            }
        }
        backtrack(0, 0, rows, cols, squares, board);
    }
private:
    bool backtrack(int row, int col, 
                   vector<unordered_set<int>>& rows, 
                   vector<unordered_set<int>>& cols, 
                   vector<vector<unordered_set<int>>>& squares,
                   vector<vector<char>>& board) {
        
        if (row == 9) return true;

        int nextRow = col == 8 ? row + 1 : row; 
        int nextCol = col == 8 ? 0 : col + 1;

        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; ++i) {
                if (!rows[row].count(i) && !cols[col].count(i) &&
                    !squares[row/3][col/3].count(i)) {

                    board[row][col] = (char)(i + '0');
                    rows[row].insert(i);
                    cols[col].insert(i);
                    squares[row/3][col/3].insert(i);

                    if (backtrack(nextRow, nextCol, rows, cols, squares, board)) {
                        return true;
                    } 

                    board[row][col] = '.';
                    rows[row].erase(i);
                    cols[col].erase(i);
                    squares[row/3][col/3].erase(i);
                }
            }
            return false;
        } else {
            return backtrack(nextRow, nextCol, rows, cols, squares, board);
        }
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
    solution.solveSudoku(board);
    for (int i = 0; i < board.size(); ++i) {
        cout << "[";
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
            if (j < board[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}