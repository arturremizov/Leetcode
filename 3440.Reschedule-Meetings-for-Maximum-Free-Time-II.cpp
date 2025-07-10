#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        vector<bool> canReschedule(n);
        int leftFreeSpace = 0;
        for (int i = 0; i < n; ++i) {
            if (endTime[i] - startTime[i] <= leftFreeSpace) {
                canReschedule[i] = true;
            }
            leftFreeSpace = max(leftFreeSpace, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));
        }

        int rightFreeSpace = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (endTime[i] - startTime[i] <= rightFreeSpace) {
                canReschedule[i] = true;
            }
            if (i == 0) break;
            rightFreeSpace = max(
                rightFreeSpace,
                (i == n - 1 ? eventTime : startTime[i + 1]) - endTime[i]
            );
        }


        int result = 0;
        for (int i = 0; i < n; ++i) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (canReschedule[i]) {
                result = max(result, right - left);
            } else {
                result = max(result, right - left - (endTime[i] - startTime[i]));
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> startTime = {0,3,7,9};
    vector<int> endTime = {1,4,8,10};
    cout << solution.maxFreeTime(10,startTime,endTime) << endl; // 6
}