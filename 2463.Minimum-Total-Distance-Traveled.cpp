#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        unordered_map<string, long long> memo;
        return helper(robot, factory, robot.size() - 1, factory.size() - 1, memo);
    }
private:
    long long helper(vector<int>& robot, vector<vector<int>>& factory, int i, int j, 
                    unordered_map<string, long long>& memo) {
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        if (i < 0) return 0;
        if (j < 0) return LLONG_MAX;     

        // skip current factory
        long long result = helper(robot, factory, i, j - 1, memo);

        // use current factory
        long long cost = 0;
        int factoryLimit = factory[j][1];
        int factoryPosition = factory[j][0];
        for (int k = 0; k < min(i + 1, factoryLimit); ++k) {
            cost += abs(robot[i - k] - factoryPosition);
            long long nextFactoryResult = helper(robot, factory, i - k - 1, j - 1, memo);
            if (nextFactoryResult != LLONG_MAX) {
                result = min(result, nextFactoryResult + cost);
            }
        }
        memo[key] = result;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2}, {6,2}};
    cout << solution.minimumTotalDistance(robot, factory) << endl; // 4
}