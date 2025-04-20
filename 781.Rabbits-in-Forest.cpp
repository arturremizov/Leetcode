#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> rabbits;
        for (int answer : answers) {
            rabbits[answer]++;
        }
        int result = 0;
        for (auto [answer, count] : rabbits) {
            int groupSize = answer + 1;
            int groups = ceil((float)count / groupSize);
            result += groups * groupSize;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> answers = {1,1,2};
    cout << solution.numRabbits(answers) << endl; // 5
}
