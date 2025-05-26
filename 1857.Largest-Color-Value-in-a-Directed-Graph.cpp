#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }

        const int n = colors.size();
        int result = 0;
        unordered_set<int> visited;
        unordered_set<int> path;
        vector<vector<int>> count(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i, count, path, visited, colors, adjList));
        }
        return result == INT_MAX ? -1 : result;
    }
private:
    int dfs(int node,
            vector<vector<int>>& count,
            unordered_set<int>& path, 
            unordered_set<int>& visited,
            string& colors, 
            unordered_map<int, vector<int>>& adjList) {

        if (path.count(node)) return INT_MAX;
        if (visited.count(node)) return 0;

        visited.insert(node);
        path.insert(node);

        int colorIndex = colors[node] - 'a';
        count[node][colorIndex] = 1;

        for (int neighbor : adjList[node]) {
            if (dfs(neighbor, count, path, visited, colors, adjList) == INT_MAX) {
                return INT_MAX;
            }
            for (int col = 0; col < 26; ++col) {
                count[node][col] = max(
                    count[node][col],
                    (col == colorIndex ? 1 : 0) + count[neighbor][col]
                );
            }
        }
        path.erase(node);
        return *max_element(count[node].begin(), count[node].end());
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{0,1}, {0,2}, {2,3}, {3,4}};
    cout << solution.largestPathValue("abaca", edges) << endl; // 3
}