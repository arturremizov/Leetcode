#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        set<int> visited;
        return dfs(graph, source, destination, visited);
    }
private: 
    bool dfs(unordered_map<int, vector<int>>& graph, int node, int destination, set<int>& visited) {
        if (node == destination) return true;
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                if (dfs(graph, neighbor, destination, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << solution.validPath(3, edges, 0, 2) << endl; // true

    vector<vector<int>> edges2 = {{0,1},{1,2},{2,0}};
    cout << solution.validPath(6, edges2, 0, 5) << endl; // false

    vector<vector<int>> edges3 = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
    cout << solution.validPath(10, edges3, 5, 9) << endl; // true
}