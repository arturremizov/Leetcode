#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        const int n = edges1.size() + 1;
        const int m = edges2.size() + 1;
        
        unordered_map<int, vector<int>> adjList1;
        for (auto& edge : edges1) {
            adjList1[edge[0]].push_back(edge[1]);
            adjList1[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, vector<int>> adjList2;
        for (auto& edge : edges2) {
            adjList2[edge[0]].push_back(edge[1]);
            adjList2[edge[1]].push_back(edge[0]);
        }

        vector<int> dist1(n);
        for (int i = 0; i < n; ++i) {
            dist1[i] = bfs(i, k, adjList1);
        }

        vector<int> dist2(m);
        for (int i = 0; i < m; ++i) {
            dist2[i] = bfs(i, k - 1, adjList2);
        }
        int maxCount2 = *max_element(dist2.begin(), dist2.end());

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = dist1[i] + maxCount2;
        }
        return result;
    }
private:
    int bfs(int node, int k, unordered_map<int, vector<int>>& adjList) {
        queue<pair<int, int>> queue;
        vector<bool> visited(adjList.size(), false);
        queue.push({node, 0});
        visited[node] = true;
        int count = 0;
        while (!queue.empty()) {
            auto [node, depth] = queue.front();
            queue.pop();
            if (depth > k) continue;
            ++count;
            for (int neighbor : adjList[node]) {
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                queue.push({neighbor, depth + 1});
            }
        }
        return count;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    vector<int> result = solution.maxTargetNodes(edges1,edges2,2); // [9,7,9,8,8]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}