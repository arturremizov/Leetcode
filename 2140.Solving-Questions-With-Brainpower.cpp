#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        vector<long long> cache(n);
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0], branpower = questions[i][1];
            int prevIndex = i + 1 + branpower;
            long long chooseResult = points + (prevIndex < n ? cache[prevIndex] : 0);
            long long skipResult = (i + 1) < n ? cache[i + 1] : 0;
            cache[i] = max(chooseResult, skipResult);
        }
        return cache[0];

        // return helper(0, questions, cache);
    }
private:
    long long helper(int i, vector<vector<int>>& questions, vector<int>& cache) {
        if (i >= questions.size()) return 0;
        if (cache[i] > 0) return cache[i];
        long long result1 = helper(i + 1, questions, cache); // skip
        int points = questions[i][0], branpower = questions[i][1];
        long long result2 = points + helper(i + branpower + 1, questions, cache); // choose
        cache[i] = max(result1, result2);
        return cache[i];
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    cout << solution.mostPoints(questions) << endl; // 5
}