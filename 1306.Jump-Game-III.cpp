#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        queue<int> queue;
        queue.push(start);
        vector<bool> visited(n);
        while (!queue.empty()) {
            int i = queue.front();
            queue.pop();
            if (arr[i] == 0) return true;
            if (visited[i]) continue;
            visited[i] = true;
            int left = i - arr[i];
            int right = i + arr[i];
            if (left >= 0 && !visited[left]) {
                queue.push(left);
            }
            if (right < n && !visited[right]) {
                queue.push(right);
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,2,3,0,3,1,2};
    cout << solution.canReach(nums, 5) << endl; // true
}
