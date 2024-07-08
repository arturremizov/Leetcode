#include <iostream>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int result = 0;
        for (int people = 1; people <= n; ++people) {
            result = (result + k) % people;
        }
        return result + 1;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.findTheWinner(5, 2) << endl; // 3
    cout << solution.findTheWinner(6, 5) << endl; // 1
}