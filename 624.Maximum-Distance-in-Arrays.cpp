#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int cur_min = arrays[0].front();
        int cur_max = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {
            result = max(
                result, 
                max(arrays[i].back() - cur_min, cur_max - arrays[i].front())
            );
            cur_min = min(cur_min, arrays[i].front());
            cur_max = max(cur_max, arrays[i].back());
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> arrays = {{1,2,3}, {4,5}, {1,2,3}};
    cout << solution.maxDistance(arrays) << endl; // 4
}