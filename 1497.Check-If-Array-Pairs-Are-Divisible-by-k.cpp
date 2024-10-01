#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> reminderCount;
        for (int num : arr) {
            int reminder = (num % k + k) % k;
            reminderCount[reminder]++;
        }

        for (int num : arr) {
            int reminder1 = (num % k + k) % k;
            int reminder2 = k - reminder1;
            if (reminder1 == 0) return reminderCount[0] % 2 == 0;
            if (reminderCount[reminder1] != reminderCount[reminder2]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {1,2,3,4,5,10,6,7,8,9};
    cout << solution.canArrange(arr, 5) << endl; // true
}