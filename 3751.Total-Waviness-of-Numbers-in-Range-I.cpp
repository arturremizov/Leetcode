#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int result = 0;
        for (int num = num1; num <= num2; ++num) {
            result += getWaviness(num);
        }  
        return result;
    }
private:
    int getWaviness(int num) {
        int waviness = 0;
        string strNum = to_string(num);
        for (int i = 1; i < strNum.length() - 1; ++i) {
            bool isPeak = strNum[i - 1] < strNum[i] && strNum[i] > strNum[i + 1];
            bool isValley = strNum[i - 1] > strNum[i] && strNum[i] < strNum[i + 1];
            if (isPeak || isValley) {
                ++waviness;
            }
        }        
        return waviness;
    }
};

int main() {
    Solution solution; 
    cout << solution.totalWaviness(120, 130) << endl; // 3
}