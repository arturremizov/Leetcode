#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adjacencyList;
        for (int i = 0; i < edges.size(); ++i) {
            int source = edges[i][0], destination = edges[i][1];
            adjacencyList[source].push_back({destination, succProb[i]});
            adjacencyList[destination].push_back({source, succProb[i]});
        }

        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1, start_node});
        unordered_set<int> visited;
        
        while (!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            visited.insert(node);

            if (node == end_node) {
                return prob;
            }

            for (auto &[neighbor, edgeProb] : adjacencyList[node]) {
                if (visited.count(neighbor)) continue;
                maxHeap.push({prob * edgeProb, neighbor});
            }
        }
        return 0;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,1}, {1,2}, {0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    cout << solution.maxProbability(3, edges, succProb, 0, 2) << endl; // 0.25000
}