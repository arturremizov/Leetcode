#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_set<int> secrets = {0, firstPerson};
        unordered_map<int, unordered_map<int, vector<int>>> timeToAdj;
        vector<int> times;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], time = meeting[2];
            if (!timeToAdj.count(time)) {
                times.push_back(time);
            }
            timeToAdj[time][x].push_back(y);
            timeToAdj[time][y].push_back(x);
        }

        sort(times.begin(), times.end());
        for (int time : times) {
            unordered_set<int> visited;
            for (auto [source, _] : timeToAdj[time]) {
                if (secrets.count(source)) {
                    dfs(source, timeToAdj[time], visited, secrets);
                }
            }
        }
        return vector<int>(secrets.begin(), secrets.end());
    }
private:
    void dfs(int source, 
             unordered_map<int, vector<int>>& adj, 
             unordered_set<int>& visited,
             unordered_set<int>& secrets) {

        if (visited.count(source)) return;
        visited.insert(source);
        secrets.insert(source);
        for (int neighbor : adj[source]) {
            dfs(neighbor, adj, visited, secrets);
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    vector<int> result = solution.findAllPeople(6, meetings, 1); // [0,1,2,3,5]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}