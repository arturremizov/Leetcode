#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        unordered_set<int> suspicious;
        dfs(k, suspicious, adj);

        for (auto& inv : invocations) {
            if (!suspicious.count(inv[0]) && suspicious.count(inv[1])) {
                vector<int> result(n);
                iota(result.begin(), result.end(), 0);
                return result;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (suspicious.count(i)) continue;
            result.push_back(i);
        }
        return result;
    }
private:
    void dfs(int method, 
             unordered_set<int>& suspicious, 
             unordered_map<int, vector<int>>& adj) {

        if (suspicious.count(method)) return;
        suspicious.insert(method);

        for (int neighbor : adj[method]) {
            dfs(neighbor, suspicious, adj);
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> invocations = {{1,2},{0,1},{3,2}};
    vector<int> result = solution.remainingMethods(4,1,invocations); //[0,1,2,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}