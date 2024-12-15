#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        const int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (int i = 0; i < n; ++i) {
            int pass = classes[i][0], total = classes[i][1];
            double gain = calculateGain(pass, total);
            maxHeap.push({gain, {pass, total}});
        }
        
        while (extraStudents > 0) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            int pass = classInfo.first, total = classInfo.second;
            double gain = calculateGain(pass + 1, total + 1);
            maxHeap.push({gain, {pass + 1, total + 1}});
            --extraStudents;
        }

        double result = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            int pass = classInfo.first, total = classInfo.second;
            result += (double)pass / total;
        }
        return result / n;
    }
private: 
    double calculateGain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    cout << solution.maxAverageRatio(classes, 2) << endl; // 0.78333
}