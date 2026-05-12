#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& lhs, const auto& rhs) {
            return (lhs[1] - lhs[0]) < (rhs[1] - rhs[0]);
        });
        int result = 0;
        for (auto& task : tasks) {
            int actual = task[0], minimum = task[1];
            result = max(result + actual, minimum);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> tasks = {{1,2}, {2,4}, {4,8}};
    cout << solution.minimumEffort(tasks) << endl; // 8
}