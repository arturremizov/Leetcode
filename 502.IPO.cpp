#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxProfits;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;
        for (int i = 0; i < profits.size(); ++i) {
            minCapital.push({capital[i], profits[i]});
        }
        for (int i = 0; i < k; ++i) {
            while (!minCapital.empty() && minCapital.top().first <= w) {
                int profit = minCapital.top().second;
                minCapital.pop();
                maxProfits.push(profit);
            }
            if (maxProfits.empty()) break;
            w += maxProfits.top();
            maxProfits.pop();
        }
        return w;
    }
};

int main() 
{
    Solution solution; 
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    cout << solution.findMaximizedCapital(2, 0, profits, capital) << endl; // 4
}