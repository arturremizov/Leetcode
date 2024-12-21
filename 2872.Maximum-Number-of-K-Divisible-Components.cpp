#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adjacencyList;
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        dfs(0, -1, values, k, adjacencyList, result);
        return result;
    }
private:
    long long dfs(int current, int parrent, vector<int>& values, int k, unordered_map<int, vector<int>>& adjacencyList, int& result) {
        long long total = values[current];
        for (int child : adjacencyList[current]) {
            if (child == parrent) continue;
            total += dfs(child, current, values, k, adjacencyList, result);
        }
        if (total % k == 0) {
            ++result;
        }
        return total;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,2}, {1,2}, {1,3}, {2,4}};
    vector<int> values = {1,8,1,4,4};
    cout << solution.maxKDivisibleComponents(5,edges,values,6) << endl; // 2
}