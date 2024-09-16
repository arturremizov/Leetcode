#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // sort(timePoints.begin(), timePoints.end());

        // int result = 24 * 60 - timeToMin(timePoints.back()) + timeToMin(timePoints.front());
        // for (int i = 0; i < timePoints.size() - 1; i++) {
        //     result = min(result, timeToMin(timePoints[i + 1]) - timeToMin(timePoints[i]));
        // }
        // return result;

        vector<bool> exists(60 * 24, false);
        int firstMinute = 60 * 24, lastMinute = 0;
        for (string time : timePoints) {
            int minutes = timeToMin(time);
            if (exists[minutes]) return 0;
            exists[minutes] = true;

            firstMinute = min(firstMinute, minutes);
            lastMinute = max(lastMinute, minutes);
        }
        int result = 60 * 24 - lastMinute + firstMinute;
        int prev = firstMinute;
        for (int i = prev + 1; i <= lastMinute; i++) {
            if (!exists[i]) continue;
            result = min(result, i - prev);
            prev = i;
        }
        return result;
    }
private:
    int timeToMin(string time) {
        int delimiterIndex = time.find(":");
        int hour = stoi(time.substr(0, delimiterIndex));
        int minute = stoi(time.substr(delimiterIndex + 1, time.length() - delimiterIndex - 1));
        return 60 * hour + minute;
    } 
};

int main() {
    Solution solution; 
    vector<string> timePoints = {"23:59","00:00"};
    cout << solution.findMinDifference(timePoints) << endl; // 1
}