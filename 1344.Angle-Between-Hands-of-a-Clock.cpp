#include <iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourDegrees = 30 * hour + 0.5 * minutes;
        double minutesDegrees = minutes * 6;
        return min(
            abs(hourDegrees - minutesDegrees),
            360 - abs(hourDegrees - minutesDegrees)
        );
    }
};

int main() {
    Solution solution; 
    cout << solution.angleClock(3, 15) << endl; // 7.5
}