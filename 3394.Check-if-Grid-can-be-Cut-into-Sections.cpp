#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xIntervals;
        vector<pair<int, int>> yIntervals;
        for (auto& rectangle : rectangles) {
            xIntervals.push_back({rectangle[0], rectangle[2]});
            yIntervals.push_back({rectangle[1], rectangle[3]});
        }

        sort(xIntervals.begin(), xIntervals.end());
        sort(yIntervals.begin(), yIntervals.end());

        return canBeCutIntoSections(xIntervals) || canBeCutIntoSections(yIntervals);
    }
private:
    bool canBeCutIntoSections(vector<pair<int, int>>& intervals) {
        int sections = 0;
        int prevEnd = -1;
        for (auto [start, end] : intervals) {
            if (prevEnd <= start) {
                ++sections;
                if (sections == 3) return true;
            }
            prevEnd = max(prevEnd, end);
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    cout << solution.checkValidCuts(5, rectangles) << endl; // true
}