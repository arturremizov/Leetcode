#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int level = 0;
        queue<int> queue;
        vector<bool> visited(n + 1);
        queue.push(1);
        visited[1] = true;
        while (!queue.empty()) {
            const int levelSize = queue.size();
            for (int i = 0; i < levelSize; ++i) {
                int node = queue.front();
                queue.pop();
                for (int child : adj[node]) {
                    if (visited[child]) continue;
                    queue.push(child);
                    visited[child] = true;
                }
            } 
            ++level;
        }
        int maxDepth = level - 1;
        return modPow(2, maxDepth - 1);
    }
private:
    static constexpr int MOD = 1e9 + 7;
    long long modPow(long long a, long long b) {
        long long result = 1;
        while (b--) {
            result = result * a % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{1,2},{1,3},{3,4},{3,5}};
    cout << solution.assignEdgeWeights(edges) << endl; // 2
}