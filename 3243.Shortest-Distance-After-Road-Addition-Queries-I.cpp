#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjacencyList;
        for (int i = 0; i < n; ++i) {
            adjacencyList.push_back(vector<int>(1, i + 1));
        }
        vector<int> result;
        for (auto query : queries) {
            adjacencyList[query[0]].push_back(query[1]);
            result.push_back(shortestPath(n, adjacencyList));
        }
        return result;
    }
private:
    int shortestPath(int n, vector<vector<int>>& adjacencyList) {
        queue<pair<int, int>> queue;
        queue.push({0,0});
        unordered_set<int> visited;
        visited.insert(0);
        while (!queue.empty()) {
            auto [node, length] = queue.front();
            queue.pop();
            if (node == n - 1) return length;
            for (int neigbor : adjacencyList[node]) {
                if (visited.count(neigbor)) continue;
                visited.insert(neigbor);
                queue.push({neigbor, length + 1});
            }
        }
        return n - 1;
    }
};


int main() {
    Solution solution; 
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};
    vector<int> result = solution.shortestDistanceAfterQueries(5, queries); // [3,2,1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}