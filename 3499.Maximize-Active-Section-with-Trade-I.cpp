#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        const int n = s.length();
        int i = 0;
        int onesTotal = 0;
        int bestTrade = 0;
        int prevZeros = 0;
        while (i < n) {
            int curOnes = 0;
            while (i < n && s[i] == '1') {
                ++curOnes, ++i;
            }
            onesTotal += curOnes;
            
            int curZeros = 0;
            while (i < n && s[i] == '0') {
                ++curZeros, ++i;
            }

            if (prevZeros > 0 && curOnes > 0 && curZeros > 0) {
                bestTrade = max(bestTrade, prevZeros + curZeros);
            }
            prevZeros = curZeros;
        }
        return onesTotal + bestTrade;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxActiveSectionsAfterTrade("0100") << endl; // 4
}