#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& connection : connections) {
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> online;
        unordered_map<int, int> stationGroup;
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> minHeaps;
        
        for (int station = 1; station <= c; ++station) {
            dfs(station,station,online,stationGroup,minHeaps,adj);
        }

        vector<int> result;
        for (auto& query : queries) {
            int type = query[0], station = query[1];
            if (type == 1) {
                if (online.count(station)) {
                    result.push_back(station);
                    continue;
                }
                int group = stationGroup[station];
                auto& minHeap = minHeaps[group];
                while (!minHeap.empty() && !online.count(minHeap.top())) {
                    minHeap.pop();
                }
                result.push_back(!minHeap.empty() ? minHeap.top() : -1);
            } else {
                online.erase(station);
            }
        }
        return result;
    }
private:
    void dfs(int station, int groupId, 
             unordered_set<int>& online, unordered_map<int, int>& stationGroup,
             unordered_map<int, priority_queue<int, vector<int>, greater<>>>& minHeaps,
             unordered_map<int, vector<int>>& adj) {
        
        if (online.count(station)) return;
        online.insert(station);
        stationGroup[station] = groupId;
        minHeaps[groupId].push(station);

        for (int neighbor : adj[station]) {
            dfs(neighbor,groupId,online,stationGroup,minHeaps,adj);
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};
    vector<int> result = solution.processQueries(5,connections,queries); // [3,2,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}