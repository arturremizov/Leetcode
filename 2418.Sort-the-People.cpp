#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n = names.size();
        unordered_map<int, int> map; // height : index
        for (int i = 0; i < n; ++i) {
            map[heights[i]] = i;
        }
        sort(heights.begin(), heights.end(), greater<int>());
        vector<string> result;
        for (int height : heights) {
            int i = map[height];
            result.push_back(names[i]);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> result = solution.sortPeople(names, heights); // ["Mary","Emma","John"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}