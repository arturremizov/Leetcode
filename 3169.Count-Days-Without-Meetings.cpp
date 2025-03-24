#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int prevEnd = 0;
        int result = days;
        for (vector<int>& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            start = max(prevEnd + 1, start);
            int length = end - start + 1;
            prevEnd = max(prevEnd, end);
            if (length < 0) continue;
            result -= length;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    cout << solution.countDays(10, meetings) << endl; // 2
}