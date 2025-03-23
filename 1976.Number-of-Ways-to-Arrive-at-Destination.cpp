#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adjacencyList;
        for (vector<int>& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adjacencyList[u].push_back({v,time});
            adjacencyList[v].push_back({u,time});
        }

        const int MOD = 1e9 + 7;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> minHeap;
        minHeap.push({0,0});
        vector<long long> minCost(n, LLONG_MAX);
        vector<int> pathCount(n, 0);
        pathCount[0] = 1;

        while (!minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();

            for (auto [neighbor, neighborCost] : adjacencyList[node]) {
                long long currentCost = cost + neighborCost;
                if (currentCost < minCost[neighbor]) {
                    minCost[neighbor] = currentCost;
                    pathCount[neighbor] = pathCount[node];
                    minHeap.push({currentCost, neighbor});
                } else if (currentCost == minCost[neighbor]) {
                    pathCount[neighbor] = (pathCount[neighbor] + pathCount[node]) % MOD;
                }
            }
        }
        return pathCount[n-1];
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> roads = {
        {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}
    };
    cout << solution.countPaths(7, roads) << endl; // 4
}