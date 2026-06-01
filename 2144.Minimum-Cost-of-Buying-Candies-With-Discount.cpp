#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        const int n = cost.size();
        sort(cost.begin(), cost.end(), greater());
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 3 == 2) continue;
            result += cost[i];
        }
        return result;
    }
};

int main() {
    Solution solution;  
    vector<int> cost = {6,5,7,9,2,2};
    cout << solution.minimumCost(cost) << endl; // 23
}