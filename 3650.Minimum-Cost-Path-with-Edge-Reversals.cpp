#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj; // source -> (dest, weight)
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w * 2});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        vector<int> dist(n, INT_MAX);
        minHeap.push({0,0});
        dist[0] = 0;
        while (!minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            if (node == n - 1) return cost;

            for (auto [neighborNode, neighborCost] : adj[node]) {
                if (dist[neighborNode] > neighborCost + cost) {
                    dist[neighborNode] = neighborCost + cost;
                    minHeap.push({dist[neighborNode], neighborNode});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};
    cout << solution.minCost(4,edges) << endl; // 5
}