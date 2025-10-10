#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int n = energy.size();
        int result = INT_MIN;
        for (int i = n - k; i < n; ++i) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                result = max(result, sum);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> energy = {5,2,-10,-5,1};
    cout << solution.maximumEnergy(energy, 3) << endl; // 3
}