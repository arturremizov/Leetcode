#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = difficulty.size();
        vector<pair<int, int>> jobs(n); // profit, difficulty
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], difficulty[i]};
        }

        sort(jobs.begin(), jobs.end(), [](auto& left, auto& right) {
            return left.first > right.first;
        });

        sort(worker.begin(), worker.end(), greater<int>());

        int result = 0;
        int currentJobIndex = 0;
        for (int w : worker) {
            while (currentJobIndex < n && jobs[currentJobIndex].second > w) {
                ++currentJobIndex;
            }
            if (currentJobIndex == n) break;
            result += jobs[currentJobIndex].first;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};
    cout << solution.maxProfitAssignment(difficulty, profit, worker) << endl; // 100
}