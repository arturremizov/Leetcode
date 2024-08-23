#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        const int n = expression.length();
        int numerator = 0, denominator = 1;
        int i = 0;
        while (i < n) {
            int sign = 1;
            if (expression[i] == '-' || expression[i] == '+') {
                sign = (expression[i] == '-') ? -1 : 1;
                ++i;
            }

            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                ++i;
            }
            num *= sign;

            ++i; // skip / 

            int denom = 0;
            while (i < n && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                ++i;
            }


            numerator = numerator * denom + num * denominator;
            denominator *= denom;

            int gcdValue = gcd(abs(numerator), denominator);
            numerator /= gcdValue;
            denominator /= gcdValue;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution solution; 
    cout << solution.fractionAddition("-1/2+1/2") << endl; // "0/1"
}