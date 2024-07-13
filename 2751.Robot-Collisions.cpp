#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int n = positions.size();
        unordered_map<int, int> index_map;
        for (int i = 0; i < n; ++i) {
            index_map[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());

        stack<int> stack; // indices
        for (int position : positions) {
            int i = index_map[position];
            if (directions[i] == 'R') {
                stack.push(i);
            } else {
                while (!stack.empty() && healths[i]) {
                    int j = stack.top();
                    stack.pop();

                    if (healths[i] > healths[j]) {
                        healths[i]--;
                        healths[j] = 0;
                    } else if (healths[i] < healths[j]) {
                        healths[i] = 0;
                        healths[j]--;
                        stack.push(j);
                    } else {
                        healths[i] = 0;
                        healths[j] = 0;
                    }
                }
            }
        }
        
        vector<int> result;
        for (int health : healths) {
            if (health > 0) {
                result.push_back(health);
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> positions = {5,4,3,2,1};
    vector<int> healths = {2,17,9,15,10};
    string directions = "RRRRR";
    vector<int> result = solution.survivedRobotsHealths(positions, healths, directions); //2,17,9,15,10
    for (int health : result) {
        cout << health << ",";
    }
}
