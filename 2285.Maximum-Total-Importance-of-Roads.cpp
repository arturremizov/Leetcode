#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> edgeCount(n);
        for (const vector<int>& road : roads) {
            edgeCount[road[0]]++;
            edgeCount[road[1]]++;
        }
        sort(edgeCount.begin(), edgeCount.end());

        long long result = 0;
        int label = 1;
        for (int count : edgeCount) {
            result += (long long)label * count;
            ++label;
        }
        return result;
    }
};
 
int main() 
{
    Solution solution; 
    vector<vector<int>> roads = {{0,1}, {1,2}, {2,3}, {0,2}, {1,3}, {2,4}};
    cout << solution.maximumImportance(5, roads) << endl; // 43
    vector<vector<int>> roads2 = {{0,3}, {2,4}, {1,3}};
    cout << solution.maximumImportance(5, roads2) << endl; // 20
}