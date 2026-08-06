#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (digitProduct(n) % t) {
            ++n;
        }
        return n;
    }
private:
    int digitProduct(int num) {
        int product = 1;
        while (num) {
             product *= num % 10;
             num /= 10;
        }
        return product;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestNumber(15, 3) << endl; // 16
}
 