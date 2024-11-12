#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int n = items.size(), m = queries.size();
        sort(items.begin(), items.end());

        vector<pair<int, int>> queriesWithIndices;
        for (int i = 0; i < m; i++) {
            queriesWithIndices.push_back({queries[i], i});
        }
        sort(queriesWithIndices.begin(), queriesWithIndices.end());
        
        vector<int> result(m);
        int maxBeauty = 0;
        int itemIndex = 0;
        for (auto [query, queryIndex] : queriesWithIndices) {
            while (itemIndex < n && items[itemIndex][0] <= query) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                ++itemIndex;
            }
            result[queryIndex] = maxBeauty;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1,2,3,4,5,6};
    vector<int> result = solution.maximumBeauty(items, queries); // [2,4,5,5,6,6]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}