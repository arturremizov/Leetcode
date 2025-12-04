#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int result = 0;
        int flag = -1;
        for (char direction : directions) {
            if (direction == 'R') {
                if (flag == -1) {
                    flag = 1;
                } else {
                    flag++;
                }
            } else if (direction == 'L') {
                if (flag >= 0) {
                    result += flag + 1;
                    flag = 0;
                }
            } else {
                if (flag > 0) {
                    result += flag;
                }
                flag = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countCollisions("RLRSLL") << endl; // 5
}