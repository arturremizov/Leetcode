#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        if (rowOrder.empty() || colOrder.empty()) return {};
        
        unordered_map<int, int> valueToRow;
        for (int i = 0; i < rowOrder.size(); ++i) {
            int num = rowOrder[i];
            valueToRow[num] = i;
        }
        unordered_map<int, int> valueToCol;
        for (int i = 0; i < colOrder.size(); ++i) {
            int num = colOrder[i];
            valueToCol[num] = i;
        }

        vector<vector<int>> result(k, vector<int>(k));
        for (int num = 1; num <= k; ++num) {
            int row = valueToRow[num];
            int col = valueToCol[num];
            result[row][col] = num;
        }
        return result;
    }
private:
    vector<int> topologicalSort(int k, vector<vector<int>>& edges) {
        vector<int> inDegree(k + 1, 0);
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            int src = edge[0], dst = edge[1];
            adjList[src].push_back(dst);
            inDegree[dst]++;
        }

        queue<int> queue;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                queue.push(i);
            }
        }

        vector<int> order;
        //dfs
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            order.push_back(node);

            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }

        if (order.size() != k) return {};
        return order;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> rowConditions = {{1,2},{3,2}};
    vector<vector<int>> colConditions = {{2,1},{3,2}};
    vector<vector<int>> result = solution.buildMatrix(3, rowConditions, colConditions);
    cout << "[";
    for (int row = 0; row < result.size(); ++row) { 
        cout << "[";
        for (int col = 0; col < result[0].size(); ++col) {
            cout << result[row][col];
            if (col < result[0].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (row < result.size() - 1) {
            cout << ",\n";
        }
    }
    cout << "]\n";
}