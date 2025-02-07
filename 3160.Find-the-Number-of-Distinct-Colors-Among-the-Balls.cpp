#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        for (auto query : queries) {
            int index = query[0], color = query[1];

            if (balls.count(index)) {
                int prevColor = balls[index];
                colors[prevColor]--;
                if (colors[prevColor] == 0) {
                    colors.erase(prevColor);
                }
            }

            colors[color]++;
            balls[index] = color;
            result.push_back(colors.size());
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};
    vector<int> result = solution.queryResults(4,queries); // [1,2,2,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}