#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (const int num : arr) {
            if (num % 2 == 1) {
                ++count;
            } else {
                count = 0;
            }
            if (count == 3) return true;
        }
        return false;
    }
};
 
int main() 
{
    Solution solution; 
    vector<int> arr = {2,6,4,1};
    cout << solution.threeConsecutiveOdds(arr) << endl; // false
    vector<int> arr2 = {1,2,34,3,4,5,7,23,12};
    cout << solution.threeConsecutiveOdds(arr2) << endl; // true
}