#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const int n = prices.size();
        long long result = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (right != 0 && prices[right - 1] - prices[right] != 1) {
                left = right;
            } 
            result += right - left + 1;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> prices = {3,2,1,4};
    cout << solution.getDescentPeriods(prices) << endl; // 7
}