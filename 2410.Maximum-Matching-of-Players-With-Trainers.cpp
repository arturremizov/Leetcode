#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        const int n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int result = 0;
        for (int i = 0, j = 0; i < n; ++i, ++j) {
            while (j < m && players[i] > trainers[j]) {
                ++j;
            }
            if (j == m) break;
             ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> players = {4,7,9};
    vector<int> trainers = {8,2,5,8};
    cout << solution.matchPlayersAndTrainers(players,trainers) << endl; // 2
}