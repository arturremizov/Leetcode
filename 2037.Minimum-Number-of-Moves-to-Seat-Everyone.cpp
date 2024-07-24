#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int result = 0;
        for (int i = 0; i < seats.size(); i++) {
            result += abs(seats[i] - students[i]);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> seats = {3,1,5};
    vector<int> students = {2,7,4};
    cout << solution.minMovesToSeat(seats, students) << endl; // 4
}