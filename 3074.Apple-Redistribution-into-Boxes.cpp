#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater());
        int result = 0;
        for (int c : capacity) {
            apples -= c;
            ++result;
            if (apples <= 0) break;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> apple = {1,3,2};
    vector<int> capacity = {4,3,1,5,2};
    cout << solution.minimumBoxes(apple,capacity) << endl; // 2
}