#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int curAltitude = 0;
        for (int g : gain) {
            curAltitude += g;
            result = max(result, curAltitude);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> gain = {-5,1,5,0,-7};
    cout << solution.largestAltitude(gain) << endl; // 1
}