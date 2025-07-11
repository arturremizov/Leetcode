#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }
        priority_queue<pair<unsigned int, int>, vector<pair<unsigned int, int>>, greater<>> used; // end time, room number
        vector<int> count(n);
        for (vector<int>& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!used.empty() && start >= used.top().first) {
                int room = used.top().second;
                used.pop();
                available.push(room);
            }
            
            if (available.empty()) {
                auto [endTime, room] = used.top();
                used.pop();
                end = endTime + (end - start);
                available.push(room);
            }
            
            int room = available.top();
            available.pop();
            used.push({end, room});
            count[room]++;
        }

        int result = 0;
        int meetingsTotal = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingsTotal < count[i]) {
                meetingsTotal = count[i];
                result = i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> meetings = {{0,10}, {1,5}, {2,7}, {3,4}};
    cout << solution.mostBooked(2,meetings) << endl; // 0
}