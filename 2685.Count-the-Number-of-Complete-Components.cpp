#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacencyList;
        for (vector<int>& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        unordered_set<int> visited;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (visited.count(vertex)) continue;
            vector<int> component;
            dfs(vertex, component, visited, adjacencyList);
            if (isComplete(component, adjacencyList)) {
                ++result;
            }
        }
        return result;
    }
private:
    void dfs(int vertex,
             vector<int>& component,
             unordered_set<int>& visited,
             unordered_map<int, vector<int>>& adjacencyList) {

        if (visited.count(vertex)) return;
        visited.insert(vertex);
        component.push_back(vertex);
        for (int neighbor : adjacencyList[vertex]) {
            if (visited.count(neighbor)) continue;
            dfs(neighbor, component, visited, adjacencyList); 
        }
    }

    bool isComplete(vector<int>& component, unordered_map<int, vector<int>>& adjacencyList) {
        for (int vertex : component) {
            if (component.size() - 1 != adjacencyList[vertex].size()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    cout << solution.countCompleteComponents(6, edges) << endl; // 3
}