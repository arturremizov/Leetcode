#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int first = 0, last = 0;
        for (int num : derived) {
            if (num == 1) {
                last = last == 1 ? 0 : 1;
            } 
        }
        return first == last;
    }
};

int main() {
    Solution solution; 
    vector<int> derived = {1,1,0}; 
    cout << solution.doesValidArrayExist(derived) << endl; // true
}