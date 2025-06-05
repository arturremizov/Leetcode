#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rootX < rootY) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const int n = s1.size();
        UnionFind unionFind(26);
        for (int i = 0; i < n; ++i) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            unionFind.unite(a, b);
        }
        string result;
        for (char c : baseStr) {
            int smallest = unionFind.find(c - 'a');
            result += (char)(smallest + 'a');
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestEquivalentString("parker", "morris", "parser") << endl; // "makkek"
}