#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        double waitingTime = 0;
        for (const auto& customer : customers) {
            currentTime = max(currentTime, customer[0]);
            currentTime += customer[1];
            waitingTime += currentTime - customer[0];
        }
        return waitingTime / customers.size();
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> customers = {{1,2}, {2,5}, {4,3}};
    cout << solution.averageWaitingTime(customers) << endl; // 5.0
    vector<vector<int>> customers2 = {{5,2}, {5,4}, {10,3}, {20,1}};
    cout << solution.averageWaitingTime(customers2) << endl; // 3.25
}
