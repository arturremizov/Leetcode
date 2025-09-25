#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<string, int> memo;
        return dfs(0, 0, triangle, memo);
    }
private:
    int dfs(int row, int col, vector<vector<int>>& triangle, unordered_map<string, int>& memo) {
        const int rows = triangle.size();
        if (row == rows - 1) return triangle[row][col];
        string key = to_string(row) + "," + to_string(col);
        if (memo.count(key)) return memo[key];
        int result = triangle[row][col] + min(
            dfs(row + 1, col, triangle, memo), 
            dfs(row + 1, col + 1, triangle, memo)
        );
        memo[key] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << solution.minimumTotal(triangle) << endl; // 11
}