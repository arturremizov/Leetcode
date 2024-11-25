#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> adjacencyList = {
            {0, {1, 3}},
            {1, {0, 2, 4}},
            {2, {1, 5}},
            {3, {0, 4}},
            {4, {1, 3, 5}},
            {5, {2, 4}}
        };

        string boardString;
        for (auto row : board) {
            for (int value : row) {
                boardString += to_string(value);
            }
        }

        queue<tuple<int, string, int>> queue; // i, board, length
        queue.push({boardString.find('0'), boardString, 0});
        unordered_set<string> visited;
        while (!queue.empty()) {
            auto [i, board, length] = queue.front();
            queue.pop();

            if (!board.compare("123450")) {
                return length;
            }

            for (int neighbor : adjacencyList[i]) {
                swap(board[i], board[neighbor]);
                if (!visited.count(board)) {
                    queue.push({neighbor, board, length + 1});
                    visited.insert(board);
                }
                swap(board[neighbor], board[i]);
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> board = {
        {1,2,3},
        {4,0,5}
    };
    cout << solution.slidingPuzzle(board) << endl; // 1
}