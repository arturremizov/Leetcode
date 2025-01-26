#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int n = favorite.size();
        int longestCycle = 0;
        vector<bool> visited(n, false);
        vector<pair<int, int>> lengthTwoCycles;

        for (int node = 0; node < n; ++node) {
            if (visited[node]) continue;

            int start = node, current = node;
            unordered_set<int> currentVisisted;
            while (!visited[current]) {
                visited[current] = true;
                currentVisisted.insert(current);
                current = favorite[current];
            }

            if (currentVisisted.count(current)) {
                int length = currentVisisted.size();
                while (start != current) {
                    --length;
                    start = favorite[start];
                }
                longestCycle = max(longestCycle, length);
                if (length == 2) {
                    lengthTwoCycles.push_back({current, favorite[current]});
                }
            }
        }

        unordered_map<int, vector<int>> inverted;
        for (int destenation = 0; destenation < n; ++destenation) {
            int source = favorite[destenation];
            inverted[source].push_back(destenation);
        }

        int chainSum = 0;
        for (auto [node1, node2] : lengthTwoCycles) {
            chainSum += 2 + bfs(node1,node2,inverted) + bfs(node2,node1,inverted);
        }
        return max(chainSum, longestCycle);
    }
private:
    int bfs(int source, int parrent, unordered_map<int, vector<int>>& inverted) {
        queue<pair<int, int>> queue;
        queue.push({source, 0});
        int maxLength = 0;
        while (!queue.empty()) {
            auto [node, length] = queue.front();
            queue.pop();
            if (node == parrent) continue;
            maxLength = max(maxLength, length);
            for (int neighbor : inverted[node]) {
                queue.push({neighbor, length + 1});
            }
        }
        return maxLength;
    }
};

int main() {
    Solution solution; 
    vector<int> favorite = {2,2,1,2};
    cout << solution.maximumInvitations(favorite) << endl; // 3
}