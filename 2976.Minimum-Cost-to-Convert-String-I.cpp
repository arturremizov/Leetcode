#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj_list;
        for (int i = 0; i < original.size(); ++i) {
            char src = original[i];
            char dest = changed[i];
            int weight = cost[i];
            adj_list[src].push_back({dest, weight});
        }

        unordered_map<char, unordered_map<char, long long>> min_cost_maps;
        unordered_set<char> source_set(source.begin(), source.end());
        for (char c : source_set) {
            min_cost_maps[c] = dijkstra(c, adj_list);
        }

        long long result = 0;
        for (int i = 0; i < source.size(); ++i) {
            char src = source[i], dst = target[i];
            if (!min_cost_maps[src].count(dst)) return -1;
            result += min_cost_maps[src][dst];
        }
        return result;
    }
private:
    unordered_map<char, long long> dijkstra(char src, unordered_map<char, vector<pair<char, int>>>& adj_list) {
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> min_heap;
        min_heap.push({0, src});
        unordered_map<char, long long> min_cost_map;
        while (!min_heap.empty()) {
            auto [weight, node] = min_heap.top();
            min_heap.pop();
            if (min_cost_map.count(node)) continue;
            min_cost_map[node] = weight;
            for (auto [neighbor, nei_weight] : adj_list[node]) {
                min_heap.push({weight + nei_weight, neighbor});
            }
        }
        return min_cost_map;
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