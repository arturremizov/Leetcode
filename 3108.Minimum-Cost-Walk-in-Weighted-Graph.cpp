#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
    int n;
    vector<int> parrent;
    vector<int> size;
public:
    UnionFind(int n) : n(n) {
        parrent.resize(n);
        for (int i = 0; i < n; ++i) parrent[i] = i;
        size = vector<int>(n, 1);
    }

    int find(int x) {
        if (x != parrent[x]) {
            parrent[x] = find(parrent[x]);
        }
        return parrent[x];
    }

    void unionComponents(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                parrent[x] = y;
                size[y] += size[x];
            } else {
                parrent[y] = x;
                size[x] += size[y];
            }
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind* unionFind = new UnionFind(n);
        for (auto edge : edges) {
            unionFind->unionComponents(edge[0], edge[1]);
        }

        unordered_map<int, int> componentCost;
        for (auto edge : edges) {
            int root = unionFind->find(edge[0]);
            if (!componentCost.count(root)) {
                componentCost[root] = edge[2];
            } else {
                componentCost[root] &= edge[2];
            }
        }

        vector<int> result;
        for (auto q : query) {
            int source = q[0], destination = q[1];
            int root1 = unionFind->find(source);
            int root2 = unionFind->find(destination);
            if (root1 != root2) {
                result.push_back(-1);
            } else {
                result.push_back(componentCost[root1]);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};
    vector<int> result = solution.minimumCost(5,edges,query); // [1,-1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}