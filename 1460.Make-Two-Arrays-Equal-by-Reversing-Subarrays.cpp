#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : target) {
            ++count[num];
        }
        for (int num : arr) {
            if (count[num] == 0) return false;
            count[num]--;
            if (count[num] == 0) count.erase(num);
        }
        return count.empty();    
    }
};

int main() {
    Solution solution; 
    vector<int> target = {1,2,3,4};
    vector<int> arr = {2,4,1,3};
    cout << solution.canBeEqual(target, arr) << endl; // true
}