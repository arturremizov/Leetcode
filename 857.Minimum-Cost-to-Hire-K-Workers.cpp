#include <iostream>
#include <vector>
#include <cfloat>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double result = DBL_MAX;
        vector<pair<double, int>> pairs; // rate, quality
        for (int i = 0; i < quality.size(); ++i) {
            double rate = (double)wage[i] / quality[i];
            pairs.push_back({rate,  quality[i]});
        }
        sort(pairs.begin(), pairs.end(), [](auto const &p1, auto const &p2) {
            return p1.first < p2.first;
        });

        priority_queue<int> maxHeap;
        int totalQuality = 0;
        for (auto pair : pairs) {
            const int quality = pair.second;
            maxHeap.push(quality);
            totalQuality += quality;

            if (maxHeap.size() > k) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                result = min(result, totalQuality * pair.first);
            }
        } 
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> quality = {10,20,5};
    vector<int> wage = {70,50,30};
    cout << solution.mincostToHireWorkers(quality, wage, 2) << endl; // 105.00000
    
    vector<int> quality2 = {3,1,10,10,1};
    vector<int> wage2 = {4,8,2,2,7};
    cout << solution.mincostToHireWorkers(quality2, wage2, 3) << endl; // 30.66667
}