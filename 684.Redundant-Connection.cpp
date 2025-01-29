#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> parrents;
        for (int i = 0; i <= n; ++i) parrents.push_back(i);
        vector<int> rank(n + 1, 1);

        for (auto& edge : edges) {
            if (!unionNodes(edge[0], edge[1],parrents,rank)) {
                return edge;
            }
        }
        return {};
    }
private:
    int find(int node, vector<int>& parrents) {
        if (node == parrents[node]) return node;
        parrents[node] = find(parrents[node],parrents);
        return parrents[node];
    }
    bool unionNodes(int node1, int node2, vector<int>& parrents, vector<int>& rank) {
        int parrent1 = find(node1,parrents), parrent2 = find(node2,parrents);
        if (parrent1 == parrent2) return false;

        if (rank[parrent1] > rank[parrent2]) {
            parrents[parrent2] = parrent1;
            rank[parrent1] += rank[parrent2];
        } else {
            parrents[parrent1] = parrent2;
            rank[parrent2] += rank[parrent1];
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> result = solution.findRedundantConnection(edges); //[2,3]
    cout << "[" << result[0] << "," << result[1] << "]\n";
}