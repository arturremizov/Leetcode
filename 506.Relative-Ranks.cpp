#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<pair<int, int>> scores(n); // index & value 
        for (int i = 0; i < n; ++i) {
            scores[i] = make_pair(i, score[i]); 
        }
        sort(scores.begin(), scores.end(), [](const auto &p1, const auto &p2) { 
            return p1.second > p2.second;
        });
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            string rank;
            switch (i) {
            case 0:
                rank = "Gold Medal";
                break;
            case 1:
                rank = "Silver Medal";
                break;
            case 2:
                rank = "Bronze Medal";
                break;
            default:
                rank = to_string(i + 1);
                break;
            }
            int orig_index = scores[i].first;
            result[orig_index] = rank; 
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> score = {5,4,3,2,1};
    vector<string> result = solution.findRelativeRanks(score);
    for (string rank : result) {
        cout << rank << ",";
    }
}