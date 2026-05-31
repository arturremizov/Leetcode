#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long curMass = mass;
        for (int asteroid : asteroids) {
            if (asteroid > curMass) return false;
            curMass += asteroid;
        }
        return true;
    }
};

int main() {
    Solution solution;  
    vector<int> asteroids = {3,9,19,5,21};
    cout << solution.asteroidsDestroyed(10, asteroids) << endl; // true
}