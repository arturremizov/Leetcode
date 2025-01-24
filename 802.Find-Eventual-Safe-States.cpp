#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        unordered_map<int, bool> safeNodes;
        vector<int> result;
        for (int node = 0; node < n; ++node) {
            if (isSafeNode(node,graph,safeNodes)) {
                result.push_back(node);
            }
        }
        return result;
    }
private:
    bool isSafeNode(int node, 
                    vector<vector<int>>& graph, unordered_map<int, bool>& safeNodes) {
        if (safeNodes.count(node)) return safeNodes[node];
        safeNodes[node] = false;
        for (int neighbor : graph[node]) {
            if (!isSafeNode(neighbor,graph,safeNodes)) {
                return false;
            }
        }
        safeNodes[node] = true;
        return true;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result = solution.eventualSafeNodes(graph); //[2,4,5,6]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}