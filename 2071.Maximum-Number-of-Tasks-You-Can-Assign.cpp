#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int result = 0;
        int left = 1;
        int right = min(tasks.size(), workers.size());
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canComplete(mid, tasks, workers, pills, strength)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;        
    }
private:
    bool canComplete(const int targetTasks, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        const int m = workers.size();
        multiset<int> availableWorkers;
        for (int i = m - targetTasks; i < m; ++i) {
            availableWorkers.insert(workers[i]);
        }

        for (int i = targetTasks - 1; i >= 0; --i) {
            if (*prev(availableWorkers.end()) >= tasks[i]) {
                availableWorkers.erase(prev(availableWorkers.end()));
            } else {
                if (pills == 0) return false;
                auto found = availableWorkers.lower_bound(tasks[i] - strength);
                if (found == availableWorkers.end()) {
                    return false;
                }
                --pills;
                availableWorkers.erase(found);
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> tasks = {3,2,1};
    vector<int> workers = {0,3,3};
    cout << solution.maxTaskAssign(tasks, workers, 1, 1) << endl; // 3
}
 