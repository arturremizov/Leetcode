#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int currentSum = 0;
        int result = 0;
        for (int num = 1; num <= n; ++num) {
            if (bannedSet.count(num)) continue;
            if (currentSum + num > maxSum) break;
            currentSum += num;
            ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> banned = {1,6,5};
    cout << solution.maxCount(banned,5,6) << endl; // 2
}