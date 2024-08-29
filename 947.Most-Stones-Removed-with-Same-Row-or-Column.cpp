#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        unordered_map<int, vector<int>> adjacencyList;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        
        int connectedComponents = 0;
        unordered_set<int> visited;
        for (int stone = 0; stone < n; stone++) {
            if (visited.count(stone)) continue;
            dfs(adjacencyList, visited, stone);
            ++connectedComponents;
        }

        return n - connectedComponents;
    }
private:
    void dfs(unordered_map<int, vector<int>>& adjacencyList, unordered_set<int>& visited, int stone) {
        visited.insert(stone);
        for (int neighbor : adjacencyList[stone]) {
            if (visited.count(neighbor)) continue;
            dfs(adjacencyList, visited, neighbor);
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << solution.removeStones(stones) << endl; // 5
}