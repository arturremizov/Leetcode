#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacencyList;
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        int result = 0;
        for (int node = 1; node <= n; ++node) {
            if (visited.count(node)) continue;

            auto component = getConnectedComponent(node,adjacencyList,visited);
            int maxCount = 0;
            for (int source : component) {
                int groupsCount = longestPath(source,adjacencyList);
                if (groupsCount == -1) return -1;
                maxCount = max(maxCount,groupsCount);
            }
            result += maxCount;
        }
        return result;
    }
private:
    vector<int> getConnectedComponent(int source, 
                                      unordered_map<int, vector<int>>& adjacencyList,
                                      unordered_set<int>& visited) {
        queue<int> queue ({source});
        vector<int> component;
        visited.insert(source);

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            component.push_back(node);
            for (int neighbor : adjacencyList[node]) {
                if (visited.count(neighbor)) continue;
                queue.push(neighbor);
                visited.insert(neighbor);
            }
        }
        return component;
    }
    int longestPath(int source, unordered_map<int, vector<int>>& adjacencyList) {
        queue<pair<int, int>> queue ({{source, 1}}); // node : group
        unordered_map<int, int> distance {{source, 1}}; // node -> length from source + 1
        int result = 1;
        while (!queue.empty()) {
            auto [node, group] = queue.front();
            queue.pop();
            for (int neighbor : adjacencyList[node]) {
                if (distance.count(neighbor)) {
                    if (distance[neighbor] == group) {
                        return -1;
                    }
                    continue;
                }
                queue.push({neighbor, group + 1});
                distance[neighbor] = group + 1;
                result = max(result, group + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}};
    cout << solution.magnificentSets(6,edges) << endl; // 4
}