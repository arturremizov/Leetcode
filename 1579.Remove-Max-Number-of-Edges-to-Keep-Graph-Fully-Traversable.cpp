#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int n;

public:
    UnionFind(int n) : n(n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 0; i < n + 1; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];           
        }
        return x;
    }

    int unionSets(int x, int y) {
        int parrent1 = find(x);
        int parrent2 = find(y);
        if (parrent1 == parrent2) return 0;

        if (rank[parrent1] > rank[parrent2]) {
            rank[parrent1] += rank[parrent2];
            parent[parrent2] = parrent1;
        } else {
            rank[parrent2] += rank[parrent1];
            parent[parrent1] = parrent2;
        }
        --n;
        return 1;
    }

    bool isConnected() {
        return n == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int count = 0;

        for (const auto& edge: edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 3) {
                count += (alice.unionSets(u, v) | bob.unionSets(u, v));
            }
        }

        for (const auto& edge: edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 1) {
                count += alice.unionSets(u, v);
            }
            if (type == 2) {
                count += bob.unionSets(u, v);
            }
        }

        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - count;
        }
        return -1;        
    }
};
 
int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{3,1,2}, {3,2,3}, {1,1,3}, {1,2,4}, {1,1,2}, {2,3,4}};
    cout << solution.maxNumEdgesToRemove(4, edges) << endl; // 2
    vector<vector<int>> edges2 = {{3,1,2}, {3,2,3}, {1,1,4}, {2,1,4}};
    cout << solution.maxNumEdgesToRemove(4, edges2) << endl; // 0
}