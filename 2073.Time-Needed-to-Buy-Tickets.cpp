#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       int result = 0;
       for (int i = 0; i < tickets.size(); i++) {
            if (i < k) {
                result += min(tickets[k], tickets[i]);
            } else if (i == k) {
                result += tickets[i];
            } else {
                result += min(tickets[k] - 1, tickets[i]);
            }
       }
       return result; 
    }
};

int main() 
{
    Solution solution; 
    vector<int> tickets = {2,3,2};
    cout << solution.timeRequiredToBuy(tickets, 2) << endl;
    vector<int> tickets2 = {5,1,1,1};
    cout << solution.timeRequiredToBuy(tickets2, 0) << endl;
}