#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    const int INF = 2e9;
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currentShortestDistance = dijkstra(edges, n, source, destination);

        if (currentShortestDistance < target) return {};
        bool isEqualToTarget = currentShortestDistance == target;

        for (auto& edge : edges) {
            if (edge[2] > 0) continue;
            edge[2] = isEqualToTarget ? INF : 1;

            if (!isEqualToTarget) {
                long long newDistance = dijkstra(edges, n, source, destination);
                if (newDistance <= target) {
                    isEqualToTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return isEqualToTarget ? edges : vector<vector<int>>{};
    }

private:
    long long dijkstra(vector<vector<int>>& edges, int nodeCount, int source, int destination) {
        unordered_map<int, vector<pair<int, long long>>> adjacencyList;
        for (auto& edge : edges) {
            int src = edge[0], dst = edge[1];
            long long distance = edge[2];

            if (distance == -1) continue;
            adjacencyList[src].emplace_back(dst, distance);
            adjacencyList[dst].emplace_back(src, distance);
        }

        vector<long long> minDistance(nodeCount, INF);
        minDistance[source] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        minHeap.push({0, source});

        while (!minHeap.empty()) {
            auto [currentDist, node] = minHeap.top();
            minHeap.pop();

            if (currentDist > minDistance[node]) continue;

            if (adjacencyList.find(node) != adjacencyList.end()) {
                for (auto& [v, weight] : adjacencyList[node]) {
                    if (minDistance[node] + weight < minDistance[v]) {
                        minDistance[v] = minDistance[node] + weight;
                        minHeap.push({minDistance[v], v});
                    }
                }
            }
        }

        return minDistance[destination];
    }
};


int main() {
    Solution solution; 
    vector<vector<int>> edges = {{4,1,-1},{2,0,-1},{0,3,-1},{4,3,-1}};
    vector<vector<int>> result = solution.modifiedGraphEdges(5, edges, 0, 1, 5);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}