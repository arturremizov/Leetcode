#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> incomingEdges(n);
        for (auto edge : edges) {
            incomingEdges[edge[1]]++;
        }
        int result = -1;
        for (int i = 0; i < n; ++i) {
            if (incomingEdges[i] == 0) {
                if (result != -1) return -1;
                result = i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> edges = {{0,1},{1,2}};
    cout << solution.findChampion(3, edges) << endl; // 0
}