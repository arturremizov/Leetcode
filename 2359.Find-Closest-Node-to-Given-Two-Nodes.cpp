#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i) {
            if (edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }

        unordered_map<int, int> dist1 = bfs(node1, adj); 
        unordered_map<int, int> dist2 = bfs(node2, adj);

        int result = -1;
        int curMaxDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dist1.count(i) && dist2.count(i)) {
                int dist = max(dist1[i], dist2[i]);
                if (dist < curMaxDist) {
                    result = i;
                    curMaxDist = dist;
                }
            }
        }
        return result;
    }
private:
    unordered_map<int, int> bfs(int node, unordered_map<int, vector<int>>& adj) {
        unordered_map<int, int> distMap;
        queue<pair<int, int>> queue;
        queue.push({node, 0});
        distMap[node] = 0;
        while (!queue.empty()) {
            auto [node, dist] = queue.front();
            queue.pop();
            for (int neighbor : adj[node]) {
                if (distMap.count(neighbor)) continue;
                queue.push({neighbor, dist + 1});
                distMap[neighbor] = dist + 1;
            }
        }   
        return distMap;
    }
};

int main() {
    Solution solution; 
    vector<int> edges = {2,2,3,-1};
    cout << solution.closestMeetingNode(edges, 0, 1) << endl; // 2
}