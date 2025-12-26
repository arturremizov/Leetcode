#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int customersCount = 0;
        for (char c : customers) {
            if (c == 'Y') ++customersCount;
        }

        int noCustomers = 0;
        int minPenalty = customersCount;
        int minHour = 0;
        for (int i = 0; i < customers.length(); ++i) {
            if (customers[i] == 'Y') {
                --customersCount;
            } else {
                ++noCustomers;
            }
            if (customersCount + noCustomers < minPenalty) {
                minPenalty = customersCount + noCustomers;
                minHour = i + 1;
            }
        }
        return minHour;
    }
};

int main() {
    Solution solution; 
    cout << solution.bestClosingTime("YYNY") << endl; // 2
}