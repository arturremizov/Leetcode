#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration, 
                           vector<int>& waterStartTime, 
                           vector<int>& waterDuration) {

        const int n = landStartTime.size(), m = waterStartTime.size();
        int result = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int land = landStartTime[i] + landDuration[i];
                int waterAfterLand = max(land, waterStartTime[j]) + waterDuration[j];

                int water = waterStartTime[j] + waterDuration[j];
                int landAfterWater = max(water, landStartTime[i]) + landDuration[i];

                result = min({result, waterAfterLand, landAfterWater});
            }
        }
        return result;
    }
};

int main() {
    Solution solution;  
    vector<int> landStartTime = {2,8};
    vector<int> landDuration = {4,1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};
    cout << solution.earliestFinishTime(landStartTime,landDuration,waterStartTime,waterDuration) << endl; // 9
}