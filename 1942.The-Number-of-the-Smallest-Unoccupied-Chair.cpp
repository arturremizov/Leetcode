#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> indexes; 
        for (int i = 0; i < times.size(); i++) indexes.push_back(i);
        sort(indexes.begin(), indexes.end(), [&times](const int& lhs, const int& rhs) {
            return times[lhs][0] < times[rhs][0];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> usedChairs; // leave time, chair
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < times.size(); i++) {
            availableChairs.push(i);
        }
        
        for (int i : indexes) {
            int arrive = times[i][0];
            int leave = times[i][1];
            
            while (!usedChairs.empty() && usedChairs.top().first <= arrive) {
                auto [_, chair] = usedChairs.top();
                usedChairs.pop();
                availableChairs.push(chair);
            }
            
            int availableChair = availableChairs.top();
            availableChairs.pop();
            usedChairs.push({leave, availableChair});

            if (i == targetFriend) {
                return availableChair;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> times = {{1,4}, {2,3}, {4,6}};
    cout << solution.smallestChair(times,1) << endl; // 1
}