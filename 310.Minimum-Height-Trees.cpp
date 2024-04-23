#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        unordered_map<int, vector<int>> adjacencyList;
        for (vector<int> edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            adjacencyList[node1].push_back(node2); 
            adjacencyList[node2].push_back(node1); 
        }

        unordered_map<int, int> edgesCount;
        queue<int> leaves;
        for (auto it : adjacencyList) {
            int source = it.first;
            int neighborsCount = it.second.size();
            if (neighborsCount == 1) {
                leaves.push(source);
            }
            edgesCount[source] = neighborsCount; 
        }

        vector<int> result;
        while (!leaves.empty()) {
            if (n <= 2) {
                while (!leaves.empty()) {
                    result.push_back(leaves.front());
                    leaves.pop();
                }
                break;
            }
            int length = leaves.size();
            for (int i = 0; i < length; ++i) {
                int node = leaves.front();
                leaves.pop();
                --n;
                for (int neighbor : adjacencyList[node]) {
                    edgesCount[neighbor]--;
                    if (edgesCount[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{1,0}, {1,2}, {1,3}};
    vector<int> result = solution.findMinHeightTrees(4, edges);
    for (int num : result) {
        cout << num << endl;
    }
}