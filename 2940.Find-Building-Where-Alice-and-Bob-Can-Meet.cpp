#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int n = queries.size();
        const int m = heights.size();

        vector<int> result(n, -1);
        unordered_map<int, vector<pair<int, int>>> groups;
        
        for (int i = 0; i < n; ++i) {
            int left = min(queries[i][0], queries[i][1]);
            int right = max(queries[i][0], queries[i][1]);
            if (left == right || heights[right] > heights[left]) {
                result[i] = right;
            } else {
                int height = max(heights[left], heights[right]);
                groups[right].push_back({height, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < m; ++i) {
            for (auto [queryHeight, queryIndex] : groups[i]) {
                minHeap.push({queryHeight, queryIndex});
            }
            while (!minHeap.empty() && heights[i] > minHeap.top().first) {
                auto [_, queryIndex] = minHeap.top();
                minHeap.pop();
                result[queryIndex] = i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> heights = {6,4,8,5,2,7};
    vector<vector<int>> queries = {{0,1},{0,3},{2,4},{3,4},{2,2}};

    vector<int> result = solution.leftmostBuildingQueries(heights, queries); // [2,5,-1,5,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}