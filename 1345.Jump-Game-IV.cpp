#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int, vector<int>> numToIndices;
        for (int i = 0; i < n; ++i) {
            numToIndices[arr[i]].push_back(i);
        }
        queue<int> queue;
        queue.push(0);
        vector<bool> visited(n);
        visited[0] = true;
        int result = 0;
        while (!queue.empty()) {
            int levelSize = queue.size();
            while (levelSize--) {
                int i = queue.front();
                queue.pop();
                if (i == n - 1) return result;
                
                if (!visited[i + 1]) {
                    queue.push(i + 1);
                    visited[i + 1] = true;
                }

                if (i > 0 && !visited[i - 1]) {
                    queue.push(i - 1);
                    visited[i - 1] = true;
                }

                for (int j : numToIndices[arr[i]]) {
                    if (!visited[j]) {
                        queue.push(j);
                        visited[j] = true;
                    }
                }
                numToIndices.erase(arr[i]);
            }
            ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << solution.minJumps(arr) << endl; // 3
}
