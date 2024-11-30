#include <iostream>
#include <vector>
#include <unordered_map> 
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> outDegree, inDegree; 
        for (auto pair : pairs) {
            adjacencyList[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        int startNode = pairs[0][0];
        for (auto [node, _] : adjacencyList) {
            if (outDegree[node] - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        vector<int> eulerianPath;
        stack<int> stack;
        stack.push(startNode);
        while (!stack.empty()) {
            int node = stack.top();
            if (!adjacencyList[node].empty()) {
                int next = adjacencyList[node].back();
                adjacencyList[node].pop_back();
                stack.push(next);
            } else {
                eulerianPath.push_back(node);
                stack.pop();
            }
        }

        reverse(eulerianPath.begin(), eulerianPath.end());

        vector<vector<int>> result;
        for (int i = 0; i < eulerianPath.size() - 1; ++i) {
            result.push_back({eulerianPath[i], eulerianPath[i + 1]});
        }
        return result;
    }   
};

int main() {
    Solution solution; 
    vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};
    vector<vector<int>> result = solution.validArrangement(pairs); // [[11,9],[9,4],[4,5],[5,1]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}