#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            adjList[from].push_back({to, weight});
            adjList[to].push_back({from, weight});
        }

        int result = -1;
        int minCount = n;
        for (int source = 0; source < n; ++source) {
            int count = dijkstra(source, adjList, distanceThreshold);
            if (count <= minCount) {
                result = source;
                minCount = count;
            }
        }
        return result;
    }
private:
    int dijkstra(int source, unordered_map<int, vector<pair<int,int>>>& adjList, int distanceThreshold) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap; // weight, node
        minHeap.push({0, source});
        unordered_set<int> visited;

        while (!minHeap.empty()) {
            auto [weight, node] = minHeap.top();
            minHeap.pop();

            if (visited.count(node)) continue;
            visited.insert(node);

            for (auto& [neighbor, weight2] : adjList[node]) {
                int neighborWeight = weight + weight2;
                if (neighborWeight <= distanceThreshold) {
                    minHeap.push({neighborWeight, neighbor});
                }
            }
        }
        return visited.size() - 1;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << solution.findTheCity(4, edges, 4) << endl; // 3
}