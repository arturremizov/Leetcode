#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int,vector<int>> adjacencyList;
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> bobTimesToRoot; 
        dfs(bob, -1, 0, bobTimesToRoot, adjacencyList);

        int result = INT32_MIN;
        queue<tuple<int, int, int, int>> queue; 
        queue.push({0, 0, -1, amount[0]}); //(node, time, previous, total profit)
        while (!queue.empty()) {
            auto [node, time, previous, profit] = queue.front();
            queue.pop();
            bool isLeaf = true;
            for (int neighboor : adjacencyList[node]) {
                if (neighboor == previous) continue;
                isLeaf = false;

                int neighboorProfit = amount[neighboor];
                int neighboorTime = time + 1;
                if (bobTimesToRoot.count(neighboor)) {
                    if (neighboorTime > bobTimesToRoot[neighboor]) {
                        neighboorProfit = 0;
                    } else if (neighboorTime == bobTimesToRoot[neighboor]) {
                        neighboorProfit = amount[neighboor] / 2;
                    }
                }
                queue.push({neighboor, neighboorTime, node, profit + neighboorProfit});
            }
            if (isLeaf) {
                result = max(result, profit);
            }
        }
        return result;
    }
private:
    bool dfs(int source, int previous, int time,  
             unordered_map<int, int>& bobTimesToRoot,
             unordered_map<int,vector<int>>& adjacencyList) {

        if (source == 0) {
            bobTimesToRoot[source] = time;
            return true;
        }

        for (int neighboor : adjacencyList[source]) {
            if (neighboor == previous) continue;
            if (dfs(neighboor, source, time + 1, bobTimesToRoot, adjacencyList)) {
                bobTimesToRoot[source] = time;
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    vector<int> amount = {-2,4,2,-4,6};
    cout << solution.mostProfitablePath(edges,3,amount) << endl; // 6
}