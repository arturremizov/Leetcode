#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> stack;
        for (int i = 0; i < prices.size(); ++i) {
            while (!stack.empty() && prices[stack.top()] >= prices[i] ) {
                int j = stack.top();
                result[j] -= prices[i];
                stack.pop();
            }
            stack.push(i);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> prices = {8,4,6,2,3};
    vector<int> result = solution.finalPrices(prices); // [4,2,4,2,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}