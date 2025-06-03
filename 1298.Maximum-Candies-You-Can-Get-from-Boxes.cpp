#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        const int n = status.size();
        int result = 0;
        queue<int> queue;
        vector<bool> visited(n), canOpenBoxes(n), hasKey(n);
        for (int box : initialBoxes) {
            if (status[box] == 0) {
                canOpenBoxes[box] = true;
            } else {
                queue.push(box);
                visited[box] = true;
                result += candies[box];
            }
        }

        while (!queue.empty()) {
            int box = queue.front();
            queue.pop();
            for (int key : keys[box]) {
                hasKey[key] = true;
                if (!visited[key] && canOpenBoxes[key]) {
                    queue.push(key);
                    visited[key] = true;
                    result += candies[key];
                }
            }

            for (int neighbor : containedBoxes[box]) {
                if (visited[neighbor]) continue;
                if (status[neighbor] == 0 && !hasKey[neighbor] ) {
                    canOpenBoxes[neighbor] = true;
                } else {
                    queue.push(neighbor);
                    visited[neighbor] = true;
                    result += candies[neighbor];
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> status = {1,0,1,0};
    vector<int> candies = {7,5,4,100};
    vector<vector<int>> keys = {{},{},{1},{}};
    vector<vector<int>> containedBoxes = {{1,2},{3},{},{}};
    vector<int> initialBoxes = {0};
    cout << solution.maxCandies(status,candies,keys,containedBoxes,initialBoxes) << endl; //16
}