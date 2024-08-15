#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (five == 0) return false; 
                --five;
                ++ten;
            } else if (bill == 20) {
                if (ten > 0 && five > 0) {
                    --ten, --five;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() 
{
    Solution solution; 
    vector<int> bills = {5,5,5,10,20};
    cout << solution.lemonadeChange(bills) << endl; // true
    vector<int> bills2 = {5,5,10,10,20};
    cout << solution.lemonadeChange(bills2) << endl; // false
}