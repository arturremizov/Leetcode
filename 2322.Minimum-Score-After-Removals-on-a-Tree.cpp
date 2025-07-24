#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        const int n = nums.size();

        unordered_map<int, vector<int>> adjList;
        for (vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }


        vector<int> inTime(n), outTime(n), xorSum(n);
        int time = 0;
        dfs(0, -1, time, adjList, nums, inTime, outTime, xorSum);

        int totalXor = xorSum[0];
        int result = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = xorSum[i], b = xorSum[j], c;
                if (isAncestor(i, j, inTime, outTime)) {
                    a ^= b;
                    c = totalXor ^ xorSum[i];
                } else if (isAncestor(j, i, inTime, outTime)) {
                    b ^= a;
                    c = totalXor ^ xorSum[j];
                } else {
                    c = totalXor ^ a ^ b;
                }
                int maxVal = max({a, b, c});
                int minVal = min({a, b, c});
                result = min(result, maxVal - minVal);
            }
        
        }
        return result;
    }
private:
    void dfs(int node, int parrent, int& time,
             unordered_map<int, vector<int>>& adjList,
             vector<int>& nums,
             vector<int>& inTime, vector<int>& outTime, vector<int>& xorSum) {
            
        xorSum[node] = nums[node];
        inTime[node] = time++;
        for (int child : adjList[node]) {
            if (child == parrent) continue;
            dfs(child, node, time, adjList, nums, inTime, outTime, xorSum);
            xorSum[node] ^= xorSum[child];
        }
        outTime[node] = time++;
    }
    
    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,5,5,4,11};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    cout << solution.minimumScore(nums,edges) << endl; // 9
}