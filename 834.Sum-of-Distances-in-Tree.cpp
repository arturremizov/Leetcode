#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacencyList;
        for (vector<int> edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        vector<int> count(n, 1);
        vector<int> result(n, 0);
        dfs(adjacencyList, 0, -1, count, result);
        dfs2(n, adjacencyList, 0, -1, count, result);
        return result;
    }
private: 
    void dfs(unordered_map<int, vector<int>>& adjList, int node, int parrent, vector<int>& count, vector<int>& result) {
        for (int neighbor : adjList[node]) {
            if (neighbor != parrent) {
                dfs(adjList, neighbor, node, count, result);
                count[node] += count[neighbor];
                result[node] += result[neighbor] + count[neighbor];
            }
        }
    }
    void dfs2(int n, unordered_map<int, vector<int>>& adjList, int node, int parrent, vector<int>& count, vector<int>& result) {
        for (int neighbor : adjList[node]) {
            if (neighbor != parrent) {
                result[neighbor] = result[node] - count[neighbor] + (n - count[neighbor]);
                dfs2(n, adjList, neighbor, node, count, result);
            }
        }
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{0,1}, {0,2}, {2,3}, {2,4}, {2,5}};
    vector<int> result = solution.sumOfDistancesInTree(6, edges); // 8,12,6,10,10,10
    for (int num : result) {
        cout << num << ",";
    }
}