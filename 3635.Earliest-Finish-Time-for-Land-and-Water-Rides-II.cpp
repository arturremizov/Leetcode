#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration, 
                           vector<int>& waterStartTime, 
                           vector<int>& waterDuration) {

        int landToWater = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterToLand = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(landToWater, waterToLand);
    }
private:
    int solve(vector<int> start1, vector<int>& duration1, 
              vector<int> start2, vector<int>& duration2) {
            
        int endTime1 = INT_MAX;
        for (int i = 0; i < start1.size(); ++i) {
            endTime1 = min(endTime1, start1[i] + duration1[i]);
        }
        int endTime2 = INT_MAX;
        for (int i = 0; i < start2.size(); ++i) {
            int startTime2 = max(endTime1, start2[i]);
            endTime2 = min(endTime2, startTime2 + duration2[i]);
        }
        return endTime2;
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