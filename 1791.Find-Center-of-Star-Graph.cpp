#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        const int n = edges.size();
        unordered_map<int, int> degree; // node -> degree
        for (vector<int> edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        } 
        for (const auto& [node, nodeDegree] : degree) {
            if (nodeDegree == n) return node;
        }
        return -1;        
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{1,2}, {2,3}, {4,2}};
    cout << solution.findCenter(edges) << endl; // 2
    vector<vector<int>> edges2 = {{1,2}, {5,1}, {1,3}, {1,4}};
    cout << solution.findCenter(edges2) << endl; // 1
}