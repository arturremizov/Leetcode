#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : edges) {
            int vertex1 = edge[0], vertex2 = edge[1];
            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1);
        }

        queue<int> queue;
        int currentTime = 0;
        unordered_map<int, vector<int>> visitedTimes; // node : [time]
        int result = -1;
        
        queue.push(1);

        while (!queue.empty()) {
            int length = queue.size();
            for (int i = 0; i < length; i++) {
                int node = queue.front();
                queue.pop();

                if (node == n) {
                    if (result != -1) {
                        return currentTime;
                    } 
                    result = currentTime;
                } 
                for (int neighbor : adjList[node]) {
                    auto& neighborTimes = visitedTimes[neighbor];
                    if (neighborTimes.empty() || (neighborTimes.size() == 1 && neighborTimes[0] != currentTime)) {
                        queue.push(neighbor);
                        neighborTimes.push_back(currentTime);
                    }
                }   
            }
            if ((currentTime / change) % 2 == 1) {
                currentTime += change - (currentTime % change);
            }
            currentTime += time;
        }
        return -1;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    cout << solution.secondMinimum(5,edges,3,5) << endl; // 13
}