#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == '1') {
                    heights[col]++;
                } else {
                    heights[col] = 0;
                }
            }
            result = max(result, helper(heights));
        }
        return result;
    }
private:
    int helper(vector<int>& heights) {  
        stack<int> stack; // monotonic increasing
        heights.push_back(0);
        int maxArea = 0;
        for (int col = 0; col < heights.size(); ++col) {
            while (!stack.empty() && heights[stack.top()] > heights[col]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? col : col - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(col);
        }
        heights.pop_back();
        return maxArea;
    }
};

int main() {
    Solution solution; 
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << solution.maximalRectangle(matrix) << endl;
}