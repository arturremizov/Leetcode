#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9+7;
        
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hDistances;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                int dist = hFences[j] - hFences[i];
                hDistances.insert(dist);
            }
        }

        int maxSide = -1;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                int dist = vFences[j] - vFences[i];
                if (hDistances.count(dist)) {
                    maxSide = max(maxSide, dist);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (1LL * maxSide * maxSide) % MOD;
    }
};

int main() {
    Solution solution; 
    vector<int> hFences = {2,3};
    vector<int> vFences = {2};
    cout << solution.maximizeSquareArea(4,3,hFences,vFences) << endl; // 4
}