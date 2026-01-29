#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, 
                          string target,
                          vector<char>& original, 
                          vector<char>& changed,
                          vector<int>& cost) {

        const int n = source.length(), m = original.size();
        unordered_map<char, vector<pair<char, int>>> adj;
        for (int i = 0; i < m; ++i) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        unordered_set<char> sourceChars(source.begin(), source.end());
        unordered_map<char, unordered_map<char, long long>> minCost;
        for (char c : sourceChars) {
            helper(c, adj, minCost);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) continue;
            if (!minCost[source[i]].count(target[i])) return -1;
            result += minCost[source[i]][target[i]];
        }
        return result;
    }
private:
    void helper(char source, 
                unordered_map<char, vector<pair<char, int>>>& adj, 
                unordered_map<char, unordered_map<char, long long>>& minCost) {
        
        priority_queue<pair<long long, char>,
                       vector<pair<long long, char>>,
                       greater<>> minHeap;

        minHeap.push({0, source});
        minCost[source][source] = 0;
        while (!minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            if (cost > minCost[source][node]) continue;
            for (auto [neighborNode, neighborCost] : adj[node]) {
                if (!minCost[source].count(neighborNode) || 
                    minCost[source][neighborNode] > cost + neighborCost) {
                    minCost[source][neighborNode] = cost + neighborCost;
                    minHeap.push({cost + neighborCost, neighborNode});
                }
            }
        }
    }
};

int main() 
{
    Solution solution; 
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    cout << solution.minimumCost("abcd", "acbe", original, changed, cost) << endl; // 28
}