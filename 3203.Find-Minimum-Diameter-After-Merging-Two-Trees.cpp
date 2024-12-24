#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const int n = edges1.size() + 1;
        const int m = edges2.size() + 1;
        unordered_map<int, vector<int>> adj1 = buildAdjacencyList(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdjacencyList(edges2);
        auto [diameter1,_] = getDiameter(0, -1, adj1);
        auto [diameter2,__] = getDiameter(0, -1, adj2);
        return max((double)diameter1, max((double)diameter2, ceil((double)diameter1 / 2) + ceil((double)diameter2 / 2) + 1));
    }
private:
    unordered_map<int, vector<int>> buildAdjacencyList(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    pair<int,int> getDiameter(int current, int parrent, unordered_map<int, vector<int>>& adj) {
        int maxDiameter = 0;
        pair<int, int> maxChildPaths = {0,0};
        for (int neigbor : adj[current]) {
            if (neigbor == parrent) continue;
            auto [neigborDiameter, neigborMaxLeafPath] = getDiameter(neigbor, current, adj);
            maxDiameter = max(maxDiameter, neigborDiameter);
            
            vector<int> paths = {maxChildPaths.first, maxChildPaths.second, neigborMaxLeafPath};
            sort(paths.begin(), paths.end());
            maxChildPaths = {paths[1], paths[2]};
        }
        maxDiameter = max(maxDiameter, maxChildPaths.first + maxChildPaths.second);
        return {maxDiameter, 1 + max(maxChildPaths.first, maxChildPaths.second)};
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}};
    vector<vector<int>> edges2 = {{0,1}};
    cout << solution.minimumDiameterAfterMerge(edges1, edges2) << endl; // 3
}