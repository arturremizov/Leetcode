#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int prevDevicesCount = 0;
        for (string& row : bank) {
            int devicesCount = 0;
            for (char c : row) {
                if (c == '1') ++devicesCount;
            }
            if (devicesCount > 0) {
                result += prevDevicesCount * devicesCount;
                prevDevicesCount = devicesCount;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> bank = {"011001","000000","010100","001000"};
    cout << solution.numberOfBeams(bank) << endl; // 8
}